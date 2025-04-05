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
int LOG = 20;
using namespace std;

vector<vector<int>> grafo;
vector<vector<int>> par;
vector<int> depth;
void dfs(int rotulo, int pai) {
	par[rotulo].assign(LOG, -1);
    par[rotulo][0] = pai;
    if(pai != -1) depth[rotulo] = depth[pai]+1;
    for(int i = 1; i < LOG; i++) {
        if(par[rotulo][i-1] == -1) break;
        par[rotulo][i] = par[ par[rotulo][i-1] ][i-1];
    }
    for(int item : grafo[rotulo]) {
        if(item != pai) dfs(item, rotulo);
    }
}

int lca(int p1, int fim){
    for(int i = LOG - 1; i >= 0; i--) {
        int x = (1 << i);
        if(par[p1][i] != -1 && fim - x >= 0){
            p1 = par[p1][i];
            fim -= x;
        }
    }
    return p1;
}

int main() {
    _; int Z; cin >> Z;
    for(int z = 0; z < Z; z++){
        int N; cin >> N;
        grafo.assign(200000,vector<int>());
        par.assign(200000, vector<int>());
        depth.assign(200000,0);
        int root = 0;
        for(int i = 0; i < N; i++) {
            int x, y; cin >> x >> y;
            if(y == 0){ root = x-1; continue; }
            grafo[y-1].pb(x-1);
            grafo[x-1].pb(y-1);
        }
        dfs(root,-1);
        int Q; cin >> Q;
        for(int i = 0; i < Q; i++){
            int k, x, y; cin >> k;
            if(k == 0){
                cin >> y >> x;
				par[x-1].assign(LOG, -1);
                par[x-1][0] = y-1;
                depth[x-1] = depth[y-1]+1; 
                for(int i = 1; i < LOG; i++) {
                    if(par[x-1][i-1] == -1) break;
                    par[x-1][i] = par[ par[x-1][i-1] ][i-1];
                }
            } else if(k == 1){
                cin >> x;
                depth[x-1] = -1;
            } else{
                cin >> x >> y;
                if(depth[x-1] >= y) cout << lca(x-1,y)+1 << endl;
                else cout << 0 << endl;
            }
        }
    }
    return 0;
}
