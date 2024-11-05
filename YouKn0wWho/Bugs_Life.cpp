#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>

using namespace std;

vector<vector<int>> grafo;
vector<int> visitados;
set<int> b1;
set<int> b2;
void dfs(int rotulo){
    visitados[rotulo] = 1;
    for(int i : grafo[rotulo]){
        if(visitados[i]){
            if(b2.count(i)) b1.insert(rotulo);
            if(b1.count(i)) b2.insert(rotulo);
        }
    }
    for(int i : grafo[rotulo]){
        if(!visitados[i]) dfs(i);
    }
}

int main(){
    // time_t inicio,fim;
    // time(&inicio);
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _; int Z; cin >> Z;
    for(int z = 0; z < Z; z++){
        cout << "Scenario #" << z+1 << ":" << endl;
        int N, M; cin >> N >> M;
        grafo.assign(N,vector<int>());
        visitados.assign(N,0);
        b1.clear();
        b2.clear();
        for(int i = 0; i < M; i++){
            int x, y; cin >> x >> y;
            grafo[x-1].pb(y-1);
            grafo[y-1].pb(x-1); 
        }
        for(int i = 0; i < N; i++){
            if(!visitados[i]){
                b1.insert(i);
                dfs(i);
            }
        }
        int imp = 0;
        for(int i = 0; i < N; i++) if(b1.count(i) && b2.count(i)) imp = 1;
        if(imp) cout << "Suspicious bugs found!" << endl;
        else cout << "No suspicious bugs found!" << endl;
    }
    // time(&fim);
    // cerr << fim - inicio << " segundos" << endl;
    return 0;
}
