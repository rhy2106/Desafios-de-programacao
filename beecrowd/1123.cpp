#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> grafo;
vector<int> precoMin;
vector<int> visitados;

void bfs(int rotulo, int fim){
    queue<int> fila;
    fila.push(rotulo);
    while(!fila.empty()){
        int pacote = fila.front();
        fila.pop();
        visitados[pacote] = 1;
        if(pacote > fim){
            for(int i = 0; i < grafo[pacote].size(); i++){
                if(grafo[pacote][i].second + precoMin[pacote] < precoMin[grafo[pacote][i].first]){
                    precoMin[grafo[pacote][i].first] = grafo[pacote][i].second + precoMin[pacote];
                    visitados[grafo[pacote][i].first] = 0;
                }
                if(!visitados[grafo[pacote][i].first]) fila.push(grafo[pacote][i].first);
            }
        } else{
            for(int i = 0; i < grafo[pacote].size(); i++){
                if(grafo[pacote][i].first != pacote+1) continue;
                if(grafo[pacote][i].second + precoMin[pacote] < precoMin[grafo[pacote][i].first]){
                    precoMin[grafo[pacote][i].first] = grafo[pacote][i].second + precoMin[pacote];
                    visitados[grafo[pacote][i].first] = 0;
                }
                if(!visitados[grafo[pacote][i].first]) fila.push(grafo[pacote][i].first);
            }
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
            int x, y, p;
            cin >> x >> y >> p;
            grafo[x].push_back(make_pair(y,p));
            grafo[y].push_back(make_pair(x,p));
        }
        if(K != C-1) bfs(K,C-1);
        cout << precoMin[C-1] << endl;
    }
    return 0;
}
