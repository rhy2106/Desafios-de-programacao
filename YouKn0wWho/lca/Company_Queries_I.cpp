#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define iPair pair<int,int>
#define uset unordered_set<int>
#define umap unordered_map<iPair,int>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

vector<vector<int>> grafo;
vector<int> depth;
vector<vector<int>> up;
int LOG;

void dfs(int rotulo, int pai) {
    up[rotulo][0] = pai;
    for(int i = 1; i < LOG; i++) {
        if(up[rotulo][i-1] == -1) break;
		up[rotulo][i] = up[up[rotulo][i-1]][i-1];
    }
    for(int f : grafo[rotulo]) {
        if (f != pai) {
            depth[f] = depth[rotulo] + 1;
            dfs(f, rotulo);
        }
    }
/*
	monta o up, que possui o pai, avo, bisavo, tataravo, etc
	de modo que up[rotulo][i] seja o antecessor 2^i de rotulo
*/
}

int lca(int rotulo, int boss) {
    for(int i = LOG - 1; i >= 0; i--){
		int x = pow(2,i);
		if(up[rotulo][i] != -1 && boss >= x) {
			rotulo = up[rotulo][i];
			boss -= x;
        }
    }
    return rotulo;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    grafo.assign(N,vector<int>());
	depth.assign(N,0);
	up.assign(N, vector<int>());
	LOG = ceil(log2(N));
	for(int i = 0; i < N; i++) up[i].assign(LOG, -1);
	for(int i = 1; i < N; i++) {
        int x; cin >> x;
        grafo[i].pb(x-1);
        grafo[x-1].pb(i);
	}
	dfs(0,-1);
	for(int i = 0; i < Q; i++){
		int x, y; cin >> x >> y;
		if(depth[x-1] < y) cout << -1 << endl;
		else cout << lca(x-1,y)+1 << endl;
	}
    return 0;
}