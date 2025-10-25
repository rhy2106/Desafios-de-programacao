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
const int MAXN = 3e5+5;
const int LOG = 22;

using namespace std;

vector<vector<int>> grafo;
vector<vector<int>> par;
vector<int> depth;

void dfs(int rotulo, int pai){
       	par[rotulo][0] = pai;
       	if(pai != -1) depth[rotulo] = depth[pai] + 1;
        for(int i = 1; i < LOG ; i++)
		if(par[rotulo][i-1] != -1)
			par[rotulo][i] = par[par[rotulo][i-1]][i-1];
	for(int item : grafo[rotulo])
		if(item != pai) dfs(item,rotulo);
}

int lca(int com, int fim){
    	if(depth[com] < depth[fim]) swap(com,fim);
    	for(int i = LOG-1; i >= 0; i--)
        	if(par[com][i] != -1 && depth[par[com][i]] >= depth[fim])
            		com = par[com][i];
	if(com == fim) return fim;
    	for(int i = LOG-1; i >= 0; i--){
        	if(par[com][i] != -1 && par[fim][i] != -1 && par[com][i] != par[fim][i]){
            		com = par[com][i];
			fim = par[fim][i];
		}
	}
    	return par[com][0];
}

int kthancestor(int x, int k){
	for(int i = 0; i < LOG; i++)
		if(par[x][i] != -1 && k & (1 << i))
			x = par[x][i];
	return x;
}

int main() {
	_; int N; cin >> N;
	grafo.assign(N,vector<int>());
	par.assign(N,vector<int>(LOG,-1));
	depth.assign(N,0);
	for(int i = 0; i < N-1; i++){
		int x, y; cin >> x >> y;
        	grafo[x-1].pb(y-1);
        	grafo[y-1].pb(x-1);
    	}
    	dfs(0,-1);
    	int M; cin >> M;
   	for(int i = 0; i < M; i++){
        	int x, y, z; cin >> x >> y >> z;
        	x--; y--;
        	int xy = lca(x,y);
		int dx = depth[x] - depth[xy];
    		int ans = kthancestor(x, min(z,dx));
		z -= dx;
		if(z <= 0){
			cout << ans+1<< endl;
			continue;
		}
		int dy = depth[y] - depth[xy];
    		if(z >= dy){
			cout << y+1 << endl;
			continue;
		}
		ans = kthancestor(y,dy-z);
		cout << ans+1 << endl;
    	}
    	return 0;
}
