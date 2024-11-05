#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> grafo;
vector<int> tempoMin;
vector<int> visitados;

void bfs(int comeco){
    queue<int> fila;
    fila.push(comeco);
    while(!fila.empty()){
        int pacote = fila.front();
        fila.pop();
        visitados[pacote] = 1;
        for(int i = 0; i < grafo[pacote].size(); i++){
            if(grafo[pacote][i].second + tempoMin[pacote] < tempoMin[grafo[pacote][i].first]){
                tempoMin[grafo[pacote][i].first] = grafo[pacote][i].second + tempoMin[pacote];
                visitados[grafo[pacote][i].first] = 0;
            }
            if(!visitados[grafo[pacote][i].first]) fila.push(grafo[pacote][i].first);
        }
    }
}

int main() {
    int N,E;
    while(cin >> N >> E, N != 0 || E != 0){
        grafo.assign(N,vector<pair<int,int>>());
        tempoMin.assign(N,999999);
        visitados.assign(N,0);
        for(int i = 0; i < E; i++){
            int x, y, h;
            cin >> x >> y >> h;
            grafo[x-1].push_back(make_pair(y-1,h));
        }
        
        for(int i = 0; i < grafo.size(); i++){
            for(int j = 0; j < grafo[i].size(); j++){
                for(int k = 0; k < grafo[grafo[i][j].first].size(); k++){
                    if(grafo[grafo[i][j].first][k].first == i) {
                        grafo[i][j].second = 0;
                        grafo[grafo[i][j].first][k].second = 0;
                    }
                }
            }
        }
        int K, O, D;
        cin >> K;
        for(int i = 0; i < K; i++){
            cin >> O >> D;
            tempoMin.assign(N,999999);
            visitados.assign(N,0);
            tempoMin[O-1] = 0;
            bfs(O-1);
            if(tempoMin[D-1] != 999999) cout << tempoMin[D-1] << endl;
            else cout << "Nao e possivel entregar a carta" << endl;
        }
        cout << endl;
    }
    return 0;
}
