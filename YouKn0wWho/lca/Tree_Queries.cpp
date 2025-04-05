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

int kth(int x, int k){
	for(int i = LOG-1; i >= 0; i--){
		if(par[x][i] != -1 && k & (1 << i))
			x = par[x][i];
	}
	return x;
}

int main(){
	_; int N, M; cin >> N >> M;
	LOG = ceil(log2(N));
	grafo.assign(N,uset());
	par.assign(N,vector<int>(LOG,-1));
	depth.assign(N,0);
	for(int i = 0; i < N-1; i++){
		int x, y; cin >> x >> y;
		grafo[x-1].insert(y-1);
		grafo[y-1].insert(x-1);
	}
	dfs(0,-1);
	while(M--){
		int q; cin >> q;
		queue<int> fila;
		int maior = 0, erro = 0;
		while(q--){
			int x; cin >> x;
			if(depth[x-1] > depth[maior]) maior = x-1;
			fila.push(x-1);
		}
		while(!fila.empty()){
			int rotulo = fila.front();
			fila.pop();
			if(rotulo == maior) continue;
			int ans = kth(maior, depth[maior] - depth[rotulo]);
			if(ans == rotulo || grafo[par[ans][0]].count(rotulo)) continue;
			erro++;
		}
		if(erro) cout << "NO" << endl;
		else cout << "YES"  << endl;
	}
	return 0;
}