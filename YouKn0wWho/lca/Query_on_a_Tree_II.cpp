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
vector<int> dist;
vector<int> depth;
int LOG;

void dfs(int rotulo, int pai, int peso){
    par[rotulo][0] = pai;
    if(pai != -1){
        depth[rotulo] = depth[pai] + 1;
        dist[rotulo] = dist[pai] + peso;
    }
    for(int i = 1; i < LOG; i++)
        if(par[rotulo][i-1] != -1)
            par[rotulo][i] = par[par[rotulo][i-1]][i-1];
    for(iPair item : grafo[rotulo])
        if(item.f != pai) dfs(item.f, rotulo, item.s);
}

int lca(int x, int y){
    if(depth[x] < depth[y]) swap(x,y);
    for(int i = LOG-1; i >= 0; i--)
        if(par[x][i] != -1 && depth[par[x][i]] >= depth[y])
            x = par[x][i];
    if(x == y) return x;
    for(int i = LOG-1; i >= 0; i--){
        if(par[x][i] != -1 && par[y][i] != -1 && par[x][i] != par[y][i]){
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}

int kth(int x, int y, int k){
    int ans = lca(x,y);
    int dx = depth[x] - depth[ans];
    int dy = depth[y] - depth[ans];
    int rotulo = x;
    if(dx < k){
        k -= dx;
        k = dy - k;
        rotulo = y;
    }
    for(int i = LOG - 1; i >= 0; i--)
        if(par[rotulo][i] != -1 && k & (1 << i))
            rotulo = par[rotulo][i];
    return rotulo+1;
}

int dist2(int x, int y){
    int ans = lca(x,y);
    return dist[x] + dist[y] - 2*dist[ans];
}

int main(){
	_; int Z; cin >> Z;
    while(Z--){
        int N; cin >> N;
        LOG = ceil(log2(N));
        grafo.assign(N,vector<iPair>());
        par.assign(N,vector<int>(LOG,-1));
        dist.assign(N,0);
        depth.assign(N,0);
        for(int i = 0; i < N-1; i++){
            int x, y, k; cin >> x >> y >> k;
            grafo[x-1].pb(mp(y-1,k));
            grafo[y-1].pb(mp(x-1,k));
        }
        dfs(0,-1,0);
        string cmd;
        while(cin >> cmd, cmd != "DONE"){
            int x, y; cin >> x >> y;
            if(cmd == "DIST"){
                cout << dist2(x-1,y-1) << endl;
                continue;
            }
            int k; cin >> k;
            cout << kth(x-1,y-1,k-1) << endl;
        }
        cout << endl;
    }
	return 0;
}