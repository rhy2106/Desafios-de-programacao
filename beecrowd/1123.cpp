#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define iPair pair<int,int>
using namespace std;

vector<vector<pair<int,int>>> grafo;
vector<int> precoMin;
vector<int> visitados;

void bfs(int rotulo, int fim){
    priority_queue<iPair,vector<iPair>, greater<iPair>> fila;
    fila.push(mp(0,rotulo));
    while(!fila.empty()){
        iPair pacote = fila.front();
        fila.pop();
        if(visitados[pacote.s]) continue;
        visitados[pacote.s] = 1;
        for(pair<int,int> item : grafo[pacote.s]){
            if(pacote.s <= fim && item.f != pacote.s+1) continue;
            precoMin[item.f] = item.s + precoMin[pacote.s];
            if(!visitados[item.f]) fila.push(mp(precoMin[item.f],item.f));
        }
    }
}

int main() {
    int N,M,C,K;
    while(cin >> N >> M >> C >> K, N != 0 || M != 0 || C != 0 || K != 0){
        grafo.assign(N,vector<pair<int,int>>());
        precoMin.assign(N,999999);
        visitados.assign(N,0);
        precoMin[K] = 0;
        for(int i = 0; i < M; i++){
            int x, y, p; cin >> x >> y >> p;
            grafo[x].pb(mp(y,p));
            grafo[y].pb(mp(x,p));
        }
        if(K != C-1) bfs(K,C-1);
        cout << precoMin[C-1] << endl;
    }
    return 0;
}
