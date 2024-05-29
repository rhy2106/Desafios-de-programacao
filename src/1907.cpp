#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grafo;
vector<int> visitados;
vector<vector<char>> matriz;
int N, M;

void dfs(int rotulo){
    if(visitados[rotulo] == 0){
        visitados[rotulo] = 1;
        int linha = rotulo/M;
        int coluna = rotulo%M;
        if(matriz[linha][coluna] == '.'){
            for(int i = 0; i < grafo[rotulo].size(); i++){
                dfs(grafo[rotulo][i]);
            }
        }
     }
}
int main() {
    cin >> N >> M;
    grafo.resize(N*M);
    visitados.resize(N*M,0);
    matriz.resize(N);
    int cont = 0;
    for(int i = 0; i < N*M; i++){
        if(i%M != 0){
            grafo[i].push_back(i-1);
        }
        if(i%M != M-1){
            grafo[i].push_back(i+1);
        }
        if(i/M != 0){
            grafo[i].push_back(i-M);
        }
        if(i/M != N-1){
            grafo[i].push_back(i+M);
        }
    }
    cin.ignore();
    for(int i = 0; i < N; i++){
        string tmp;
        getline(cin,tmp);
        for(int j = 0; j < M; j++){
            matriz[i].push_back(tmp[j]);
        }
    }
    for(int i = 0; i < grafo.size(); i++){
        if(visitados[i] == 0 && matriz[i/M][i%M] == '.'){
            cont += 1;
            dfs(i);
        } else{
            visitados[i] = 1;
        }
    }
    cout << cont << endl;
    return 0;
}