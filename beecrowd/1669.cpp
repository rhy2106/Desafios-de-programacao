#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grafo;
vector<int> visitados;
vector<int> dependencias;
vector<int> deep;
int n1, n2;

bool discoDif(int x, int y){
    return (x >= 0 && x < n1 && y >= n1 && y < n1+n2) || (y >= 0 && y < n1 && x >= n1 && x < n1+n2);
}

void dfs(int rotulo){
    vector<int> fila;
    int tmp = -1, cont = 0;
    fila.push_back(rotulo);
    while(!fila.empty()){
        int pacote = fila[fila.size()-1];
        visitados[pacote] = 1;
        if(grafo[pacote].empty()){
            deep.push_back(cont);
            tmp = fila[fila.size()-1];
            fila.pop_back();
        }
        for(int i = 0; i < grafo[pacote].size(); i++){
            if(!visitados[grafo[pacote][i]]){
                if(discoDif(pacote,grafo[pacote][i])) cont++;
                fila.push_back(grafo[pacote][i]);
                break;
            }
            if(visitados[grafo[pacote][i]] && i == grafo[pacote].size()-1){
                if(tmp != -1 && tmp != pacote) visitados[tmp] = 0;
                tmp = fila[fila.size()-1];
                fila.pop_back();
                if(discoDif(pacote,fila[fila.size()-1])) cont--;
            }
        }
    }
}
int main() {
    int d;
    while (cin >> n1 >> n2 >> d, n1 != 0 || n2 != 0 || d != 0) {
        int total = n1 + n2;
        grafo.assign(total, vector<int>());
        visitados.assign(total,0);
        dependencias.assign(total, 0);
        deep.clear();
        for (int i = 0; i < d; ++i) {
            int x, y;
            cin >> x >> y;
            grafo[y-1].push_back(x-1);
            dependencias[x-1]++;
        }
        for(int i = 0; i < total; i++){
            visitados.assign(total,0);
            if(dependencias[i] == 0) dfs(i);
        }
        int maior = 0;
        for(int i = 0; i < deep.size(); i++){
            if(deep[i] > maior) maior = deep[i];
        }
        cout << maior+2 << endl;
    }
}
