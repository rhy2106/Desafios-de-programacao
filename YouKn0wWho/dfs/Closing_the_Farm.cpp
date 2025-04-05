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
set<int> visitados;

void dfs(int rotulo){
    visitados.insert(rotulo);
    for(int i : grafo[rotulo]) if(!visitados.count(i)) dfs(i);
}

int main(){
    // time_t inicio,fim;
    // time(&inicio);
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
    _; int N, M; cin >> N >> M;
    visitados.clear();
    grafo.assign(N,vector<int>());
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y;
        grafo[x-1].pb(y-1);
        grafo[y-1].pb(x-1);
    }
    for(int i = 0; i < N; i++){
        int cont = 0;
        for(int j = 0; j < grafo.size(); j++){
            if(!grafo[j].empty() && !visitados.count(j)){
                dfs(j);
                cont++;
            }
        }
        if(cont == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
        int del; cin >> del;
        grafo[del-1].clear();
        visitados.clear();
    }
    // time(&fim);
    // cerr << fim - inicio << " segundos" << endl;
    return 0;
}
