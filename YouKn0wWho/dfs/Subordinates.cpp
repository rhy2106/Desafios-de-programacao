#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>

using namespace std;

vector<int> visitados;
vector<vector<int>> grafo;
vector<int> funcionarios;

void dfs(int inicio){
    stack<int> fila;
    fila.push(inicio);
    while(!fila.empty()){
        int pacote = fila.top();
        if(visitados[pacote]){
            for(int item : grafo[pacote]){
                funcionarios[pacote] += funcionarios[item];
            }
            fila.pop();
            continue;
        }
        visitados[pacote] = 1;
        funcionarios[pacote] = 1;
        for(int item : grafo[pacote]){
            if(!visitados[item]) fila.push(item);
        }
    }
}

int main(){
    _; int N, M; cin >> N;
    grafo.assign(N,vector<int>());
    visitados.assign(N,0);
    funcionarios.assign(N,0);
    for(int i = 1; i < N; i++){
        int x1; cin >> x1;
        grafo[x1-1].pb(i);
    }
    dfs(0);
    for(int i = 0; i < N; i++){
        cout << funcionarios[i] - 1 << " ";
    }
    cout << endl;
    return 0;
}
