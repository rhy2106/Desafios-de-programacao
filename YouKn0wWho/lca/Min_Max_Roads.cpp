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

vector<vector<iPair>> grafo;
vector<vector<int>> par;
vector<vector<int>> maxd;
vector<vector<int>> mind;
vector<int> depth;
int LOG;

void dfs(int rotulo, int pai, int peso){
    stack<iTuple> fila;
    fila.push({rotulo,pai,peso});
    while(!fila.empty()){
        int rotulo = get<0>(fila.top());
        int pai = get<1>(fila.top());
        int peso = get<2>(fila.top());
        fila.pop();
        par[rotulo][0] = pai;
        if(pai != -1){
            depth[rotulo] = depth[pai]+1;
            maxd[rotulo][0] = peso;
            mind[rotulo][0] = peso;
        }
        for(int i = 1; i < LOG; i++){
            if(par[rotulo][i-1] == -1) break;
            par[rotulo][i] = par[par[rotulo][i-1]][i-1];
            maxd[rotulo][i] = max(maxd[rotulo][i-1], maxd[par[rotulo][i-1]][i-1]);
            mind[rotulo][i] = min(mind[rotulo][i-1], mind[par[rotulo][i-1]][i-1]);
        }
        for(iPair item : grafo[rotulo]){
            if(item.f != pai) fila.push({item.f, rotulo, item.s});
        }

    }
}

iPair lca(int p1, int p2){
    int menor = INF, maior = 0;
    if(depth[p1] < depth[p2]) swap(p1,p2);
    for(int i = LOG-1; i >= 0; i--){
        if(par[p1][i] != -1 && depth[par[p1][i]] >= depth[p2]){
            maior = max(maior, maxd[p1][i]);
            menor = min(menor, mind[p1][i]);
            p1 = par[p1][i];
        }
    }
    if(p1 == p2) return mp(menor, maior);
    for(int i = LOG-1; i >= 0; i--){
        if(par[p1][i] != -1 && par[p1][i] != par[p2][i]){
            maior = max(maior, maxd[p1][i]);
            menor = min(menor, mind[p1][i]);
            maior = max(maior, maxd[p2][i]);
            menor = min(menor, mind[p2][i]);
            p1 = par[p1][i];
            p2 = par[p2][i];
        }
    }
    maior = max(maior, maxd[p1][0]);
    menor = min(menor, mind[p1][0]);
    maior = max(maior, maxd[p2][0]);
    menor = min(menor, mind[p2][0]);
    return mp(menor,maior);
}

int main() {
    // clock_t tinicio, tfim;
    // tinicio = clock();
    _; int Z; cin >> Z;
    for(int z = 0; z < Z; z++){
        cout << "Case " << z+1 << ":" << endl;
        int N; cin >> N;
        grafo.assign(N,vector<iPair>());
        par.assign(N,vector<int>());
        maxd.assign(N,vector<int>());
        mind.assign(N,vector<int>());
        depth.assign(N,0);
        LOG = ceil(log2(N));
        for(int i = 0; i < N; i++){
            par[i].assign(LOG,-1);
            maxd[i].assign(LOG,0);
            mind[i].assign(LOG,INF);
        }
        for(int i = 0; i < N-1; i++){
            int x, y, k; cin >> x >> y >> k;
            grafo[x-1].pb(mp(y-1,k));
            grafo[y-1].pb(mp(x-1,k));
        }
        dfs(0,-1,0);
        int M; cin >> M;
        for(int i = 0; i < M; i++){
            int x, y; cin >> x >> y;
            iPair resultado = lca(x-1,y-1);
            cout << resultado.f << " " << resultado.s<< endl;
        }
    }
    // tfim = clock();
    // cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
