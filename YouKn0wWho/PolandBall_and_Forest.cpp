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

void dfs(int rotulo){
    visitados[rotulo] = 1;
    for(int i : grafo[rotulo]) if(!visitados[i]) dfs(i);
}

int main(){
    time_t inicio,fim;
    time(&inicio);
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    
    _; int N, cont = 0; cin >> N;
    grafo.assign(N,vector<int>());
    visitados.assign(N,0);
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        grafo[i].pb(x-1);
        grafo[x-1].pb(i);
    }
    for(int i = 0; i < N; i++){
        if(!visitados[i]){
            dfs(i);
            cont++;
        }
    }
    cout << cont << endl;
    
    time(&fim);
    cerr << fim - inicio << " segundos" << endl;
    return 0;
}
