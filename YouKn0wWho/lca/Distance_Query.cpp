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
#define umap unordered_map<iPair,int>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

vector<vector<iPair>> grafo;
vector<vector<int>> up;
vector<vector<iPair>> dist;
vector<int> depth;
int timer;
int LOG;

void dfs(int rotulo, int pai, int peso) {
	if(pai != -1){
		dist[rotulo][0].f = peso;
		dist[rotulo][0].s = peso;
		depth[rotulo] = depth[pai] + 1;
	}
	up[rotulo][0] = pai;
    for(int i = 1; i < LOG; i++) {
        if(up[rotulo][i-1] == -1) break;
		up[rotulo][i] = up[ up[rotulo][i-1] ][i-1];
		dist[rotulo][i].f = min(dist[rotulo][i-1].f, dist[up[rotulo][i-1]][i-1].f);
		dist[rotulo][i].s = max(dist[rotulo][i-1].s, dist[up[rotulo][i-1]][i-1].s);
    }
    for(iPair item : grafo[rotulo]) {
        if(item.f != pai) dfs(item.f, rotulo, item.s);
    }
}

iPair lca(int p1, int p2){
    int menor = INF, maior = -1;
	if(depth[p1] < depth[p2]) swap(p1,p2);
	for(int i = LOG - 1; i >= 0; i--) {
        if(up[p1][i] != -1 && depth[up[p1][i]] >= depth[p2]){
			menor = min(menor, dist[p1][i].f);
			maior = max(maior, dist[p1][i].s);
			p1 = up[p1][i];
		}
	}
	if(p1 == p2) return mp(menor,maior);
	for(int i = LOG - 1; i >= 0; i--) {
        if(up[p1][i] != up[p2][i]){
			menor = min(menor, dist[p1][i].f);
			maior = max(maior, dist[p1][i].s);
			menor = min(menor, dist[p2][i].f);
			maior = max(maior, dist[p2][i].s);
			p1 = up[p1][i];
			p2 = up[p2][i];
		}
    }
	menor = min(menor, dist[p1][0].f);
	maior = max(maior, dist[p1][0].s);
	menor = min(menor, dist[p2][0].f);
	maior = max(maior, dist[p2][0].s);
	return mp(menor,maior);
}

int main() {
    int N; cin >> N;
    grafo.assign(N,vector<iPair>());
	dist.assign(N,vector<iPair>());
	up.assign(N, vector<int>());
	depth.assign(N,0);
	LOG = ceil(log2(N));
	timer = 1;
	for(int i = 0; i < N; i++){
		up[i].assign(LOG, -1);
		dist[i].assign(LOG, {INF,-1});
	}
	for(int i = 0; i < N-1; i++) {
        int x, y, k; cin >> x >> y >> k;
		grafo[y-1].pb(mp(x-1,k));
        grafo[x-1].pb(mp(y-1,k));
	}

	dfs(0,-1, 0);
	int Q; cin >> Q;
	for(int i = 0; i < Q; i++){
		int x, y; cin >> x >> y;
		iPair par = lca(x-1,y-1);
		cout << par.f << " " << par.s << endl;
	}
    return 0;
}