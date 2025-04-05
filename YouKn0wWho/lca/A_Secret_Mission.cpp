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
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

vector<vector<iPair>> grafo;
vector<vector<int>> par, maior;
vector<int> depth;
vector<int> id, floresta;
int LOG;

int find(int x){
    return id[x] = ( id[x] == x ? x : find(id[x]) );
}

void unir(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(floresta[x] > floresta[y]) swap(x,y);
    floresta[y] += floresta[x];
    id[x] = y;
}

void dfs(int rotulo, int pai, int peso) {
	par[rotulo][0] = pai;
    if(pai != -1){
        depth[rotulo] = depth[pai]+1;
        maior[rotulo][0] = peso;
    }
    for(int i = 1; i < LOG; i++) {
        if(par[rotulo][i-1] == -1) break;
        par[rotulo][i] = par[par[rotulo][i-1]][i-1];
        maior[rotulo][i] = max(maior[rotulo][i-1],maior[par[rotulo][i-1]][i-1]);
    }
    for(iPair item : grafo[rotulo]) {
        if(item.f != pai) dfs(item.f, rotulo, item.s);
    }
}

int lca(int p1, int p2){
    int m = -1;
    if(depth[p2] > depth[p1]) swap(p1,p2);
    for(int i = LOG - 1; i >= 0; i--) {
        if(par[p1][i] != -1 && depth[par[p1][i]] >= depth[p2]){
            m = max(m,maior[p1][i]);
            p1 = par[p1][i];
        }
    }
    if(p1 == p2) return m;
    for(int i = LOG - 1; i >= 0; i--) {
        if(par[p1][i] != -1 && par[p1][i] != par[p2][i]){
            m = max(m,maior[p1][i]);
            m = max(m,maior[p2][i]);
            p1 = par[p1][i];
            p2 = par[p2][i];
        }
    }
    m = max(m,maior[p1][0]);
    m = max(m,maior[p2][0]);
    return m;
}

int main() {
    _; int Z; cin >> Z;
    for(int z = 0; z < Z; z++){
		cout << "Case " << z+1 << ":" << endl;
        int N, M; cin >> N >> M;
        floresta.assign(N,1);
        id.assign(N,0); iota(id.begin(),id.end(),0);
        grafo.assign(N,vector<iPair>());
        par.assign(N, vector<int>());
        maior.assign(N, vector<int>());
        depth.assign(N,0);
        LOG = ceil(log2(N));
        for(int i = 0; i < N; i++){
            par[i].assign(LOG, -1);
            maior[i].assign(LOG,-1);
        }
        vector<iTuple> ruas;
        for(int i = 0; i < M; i++) {
            int x, y, d; cin >> x >> y >> d;
            ruas.emplace_back(d,x-1,y-1);
        }
        sort(ruas.begin(),ruas.end());
        for(iTuple item : ruas){
            int x = get<1>(item), y = get<2>(item), d = get<0>(item);
            if(find(x) != find(y)){
                unir(x,y);
                grafo[x].pb(mp(y, d));
                grafo[y].pb(mp(x, d));
            }
        }
        dfs(0,-1,0);
        int Q; cin >> Q;
        for(int i = 0; i < Q; i++){
            int x, y; cin >> x >> y;
			cout << lca(x-1,y-1) << endl;
        }
    }
    return 0;
}
