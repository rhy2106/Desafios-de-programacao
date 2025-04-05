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
vector<char> matriz;
vector<int> visitados;

void dfs(int rotulo){
    visitados[rotulo] = 1;
    if(matriz[rotulo] == '.') for(int i : grafo[rotulo]) if(!visitados[i]) dfs(i);
}

int main(){
    // time_t inicio,fim;
    // time(&inicio);
    _; int N, M; cin >> N >> M;
    matriz.clear();
    grafo.assign(N*M,vector<int>());
    visitados.assign(N*M,0);
    for(int i = 0; i < N; i++){
        string li; cin >> li;
        for(char c : li) matriz.pb(c);
    }
    
    for(int i = 0; i < N*M; i++){
        if(i%M > 0) grafo[i].pb(i-1);
        if(i%M < M-1) grafo[i].pb(i+1);
        if(i-M > 0) grafo[i].pb(i-M);
        if(i + M < M*N) grafo[i].pb(i+M);
    }
    int cont = 0;
    for(int i = 0; i < N*M; i++){
        if(!visitados[i] && matriz[i] == '.') {dfs(i); cont++;}
        visitados[i] = 1;
    }
    cout << cont << endl;
    // time(&fim);
    // cerr << fim - inicio << " segundos" << endl;
    return 0;
}
