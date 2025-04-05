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
const int LOG = 30;
 
using namespace std;
int par[MAXN][LOG];
int lca(int rotulo, int fim){
    for(int i = LOG-1; i >= 0; i--)
        if(fim & (1 << i)) rotulo = par[rotulo][i];
    return rotulo;
}
 
int main() {
    clock_t tinicio, tfim;
    tinicio = clock();
    _; int N, M; cin >> N >> M;
    for(int i = 1; i < N+1; i++) cin >> par[i][0];
    for(int l = 1; l < LOG ; l++)
        for(int i = 1; i < N+1; i++)
            par[i][l] = par[par[i][l-1]][l-1];
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
