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
const int MAXN = 2e5+5;

using namespace std;

vector<vector<iPair>> grafo;
vector<vector<int>> par;
vector<vector<int>> menor;
vector<int> depth;
int LOG;

void dfs(int rotulo, int pai, int peso){
	par[rotulo][0] = pai;
	if(pai != -1){
		depth[rotulo] = depth[pai] + 1;
		menor[rotulo][0] = peso;
	}
	for(int i = 1; i < LOG; i++){
		if(par[rotulo][i-1] == -1) break;
		par[rotulo][i] = par[par[rotulo][i-1]][i-1];
		menor[rotulo][i] = min(menor[rotulo][i-1], menor[par[rotulo][i-1]][i-1]);
	}
	for(iPair item : grafo[rotulo])
		if(item.f != pai) dfs(item.f, rotulo, item.s);
}

int lca(int x, int y){
	int m = INF;
	if(depth[x] > depth[y]) swap(x,y);
	for(int i = LOG-1; i >= 0; i--){
		if(par[y][i] != -1 && depth[par[y][i]] >= depth[x]){
			m = min(m, menor[y][i]);
			y = par[y][i];
		}
	}
	if(x == y) return m;
	for(int i = LOG-1; i >= 0; i--){
		if(par[y][i] != -1 && par[x][i] != -1 && par[y][i] != par[x][i]){
			m = min(m, menor[y][i]);
			m = min(m, menor[x][i]);
			y = par[y][i];
			x = par[x][i];
		}
	}
	m = min(m, menor[y][0]);
	m = min(m, menor[x][0]);
	return m;
}

int main(){
	_; int N, M; cin >> N >> M;
	grafo.assign(N,vector<iPair>());
	par.assign(N,vector<int>());
	menor.assign(N,vector<int>());
	depth.assign(N,0);
	LOG = ceil(log2(N));
	for(int i = 0; i < N; i++){
		par[i].assign(LOG,-1);
		menor[i].assign(LOG,INF);
	}
	for(int i = 0; i < M; i++){
		int x, y , k; cin >> x >> y >> k;
		grafo[x-1].pb(mp(y-1,k));
		grafo[y-1].pb(mp(x-1,k));
	}
	dfs(0,-1,0);
	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int x, y; cin >> x >> y;
		cout << lca(x-1,y-1) << endl;
	}
	return 0;
}