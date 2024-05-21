#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

vector<vector<int>> grafo;
vector<int> visitados;
vector<int> lista;
vector<int> lista2;
vector<vector<int>> chaves;

void bfs(int rotulo){
    if(visitados[rotulo] == 0){
        visitados[rotulo] = 1;
        for(int i = 0; i < chaves[rotulo].size(); i++){
            for(int j = 0; j < lista2.size(); j++){
                if(chaves[rotulo][i] == lista2[j]){
                    break;
                } else if(j == lista2.size()-1){
                    lista2.push_back(chaves[rotulo][i]);
                }
            }
            if(lista2.empty()){
                lista2.push_back(chaves[rotulo][i]);
            }
        }
    }
}

int main() {
    int N, M;
    while(cin >> N >> M){
        grafo.clear();
        grafo.resize(N);
        visitados.clear();
        visitados.resize(N,0);
        chaves.clear();
        chaves.resize(N);
        lista.clear();
        lista2.clear();
        for(int i = 0; i < M; i++){
            int A, B;
            cin >> A >> B;
            grafo[A-1].push_back(B-1);
            grafo[B-1].push_back(A-1);
        }
        for(int i = 1; i < N; i++){
            int chave;
            cin >> chave;
            chaves[chave-1].push_back(i);
        }
        lista.push_back(0);
        while (true){
            for(int i = 0; i < lista.size(); i = 0){
                bfs(lista[lista.size()-1]);
                if(!lista.empty()){
                    lista.pop_back();
                }
            }
            for(int i = 0; i < lista2.size(); i++){
                if(visitados[lista2[i]] == 0){
                    for(int j = 0; j < grafo[lista2[i]].size(); j++){
                        if(visitados[grafo[lista2[i]][j]] == 1){
                            lista.push_back(lista2[i]);
                            break;
                        }
                    }
                } else{
                    for(int j = 0; j < grafo[lista2[i]].size(); j++){
                        if(visitados[grafo[lista2[i]][j]] == 0){
                            lista.push_back(grafo[lista2[i]][j]);
                        }
                    }
                }
            }
            if(lista.empty()){
                break;
            }
        }

        for(int i = 0; i < M; i++){
            cout << "[";
            for(int j = 0; j < grafo[i].size(); i++){
                cout << grafo[i][j] << " ";
            }
            cout << "]";
        }
        cout << endl;
        for(int i = 0; i < N; i++){
            if(visitados[i] == 0){
                cout << "nao" << endl;
                break;
            } else if(i == N-1){
                cout << "sim" << endl;
            }
        }
    }
    return 0;
}
