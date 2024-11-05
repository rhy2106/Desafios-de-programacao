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
vector<int> gato;

void dfs(int inicio, int M){
    stack<iPair> fila;
    fila.push(mp(inicio,0));
    while(!fila.empty()){
        iPair pacote = fila.top();
        fila.pop();
        if(gato[pacote.f]) pacote.s++;
        else pacote.s = 0;
        if(pacote.s > M) continue;
        visitados[pacote.f] = 1;
        for(int item : grafo[pacote.f]){
            if(!visitados[item]) fila.push(mp(item,pacote.s));
        }
    }
}

int main(){
    _; int N, M; cin >> N >> M;
    grafo.assign(N,vector<int>());
    visitados.assign(N,0);
    gato.assign(N,0);
    for(int i = 0; i < N; i++) cin >> gato[i];
    for(int i = 0; i < N-1; i++){
        int x, y; cin >> x >> y;
        grafo[x-1].pb(y-1);
        grafo[y-1].pb(x-1);
    }
    dfs(0, M);
    int cont = 0;
    for(int i = 1; i < visitados.size(); i++) if(visitados[i] && grafo[i].size() == 1) cont++;
    cout << cont << endl;
    return 0;
}
