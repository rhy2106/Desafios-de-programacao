#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>
#define pqueue priority_queue<int,vector<int>, greater<int>>

using namespace std;

vector<vector<int>> grafo;
vector<int> visitados;
vector<int> ordem;

void dfs(int rotulo){
    pqueue fila;
    fila.push(rotulo);
    while(!fila.empty()){
        int pacote = fila.top();
        fila.pop();
        if(visitados[pacote]) continue;
        ordem.pb(pacote);
        visitados[pacote] = 1;
        for(int i : grafo[pacote]){
            if(!visitados[i]){
                fila.push(i);
            }
        }
    }
}

int main(){
    time_t inicio,fim;
    time(&inicio);
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    
    _; int N, M; cin >> N >> M;
    grafo.assign(N,vector<int>());
    visitados.assign(N,0);
    ordem.clear();
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y;
        grafo[x-1].pb(y-1);
        grafo[y-1].pb(x-1);
    }
    dfs(0);
    for(int i = 0; i < N; i++) cout << ordem[i]+1 << " ";
    cout << endl;
    
    time(&fim);
    cerr << fim - inicio << " segundos" << endl;
    return 0;
}
