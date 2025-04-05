#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set<int>
#define umap unordered_map<int,vector<int>>
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

vector<uset> grafo;
vector<vector<int>> par;
vector<int> depth;
int LOG;

void dfs(int rotulo, int pai){
	par[rotulo][0] = pai;
	if(pai != -1) depth[rotulo] = depth[pai]+1;
	for(int i = 1; i < LOG; i++){
		if(par[rotulo][i-1] != -1)
			par[rotulo][i] = par[par[rotulo][i-1]][i-1];
	}
	for(int item : grafo[rotulo])
		if(item != pai) dfs(item, rotulo);
}

int lca(int x,int y){
	if(depth[x] < depth[y]) swap(x,y);
	for(int i = LOG-1; i >= 0; i--){
		if(par[x][i] != -1 && depth[par[x][i]] >= depth[y])
			x = par[x][i];
	}
	if(x == y) return x;
	for(int i = LOG-1; i >= 0; i--){
		if(par[x][i] != -1 && par[y][i] != -1 && par[x][i] != par[y][i]){
			x = par[x][i];
			y = par[y][i];
		}
	}
	return par[x][0];
}

int kth(int x, int k){
	for(int i = LOG-1; i >= 0; i--){
		if(par[x][i] != -1 && k & (1 << i))
			x = par[x][i];
	}
	return x;
}

int main(){
	_; int N; cin >> N;
	LOG = ceil(log2(N));
	grafo.assign(N,uset());
	par.assign(N,vector<int>(LOG,-1));
	depth.assign(N,0);
	for(int i = 0; i < N-1; i++){
		int x, y; cin >> x >> y;
		grafo[x-1].insert(y-1);
		grafo[y-1].insert(x-1);
	}
	if(N != 1) dfs(0,-1);
	int M; cin >> M;
	while(M--){
		int q; cin >> q;
		if(N == 1){
			for(int i = 0; i < q; i++){
				int tmp; cin >> tmp;
				cout << "YES" << endl;
			}
			continue;
		}
		vector<int> fila;
		int erro = 0, m = 0, m2 = 0, md = 0, ans;
		while(q--){
			int x; cin >> x;
			if(depth[x-1] > depth[m]) m = x-1;
			fila.pb(x-1);
		}
		for(int item : fila){
			if(item == m) continue;
			int a = lca(m, item);
			int dist = depth[m] + depth[item] - 2*depth[a];
			if(dist > md){
				m2 = item;
				md = dist;
				ans = a;
			}
		}
		for(int item : fila){
			if(item == m || item == m2) continue;
			if(depth[item] < depth[ans]) erro++;
			if(erro) continue;
			int a = kth(m, depth[m] - depth[item]);
			if(a == item) continue;
			a = kth(m2, depth[m2] - depth[item]);
			if(a == item) continue;
			erro++;
		}
		if(erro) cout << "NO" << endl;
		else cout << "YES"  << endl;
	}
	return 0;
}