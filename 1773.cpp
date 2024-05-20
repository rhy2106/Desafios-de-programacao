#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

vector<vector<int>> grafo;
vector<int> visitados;
vector<int> lista;
vector<int> lista2;
vector<int> chaves;

void bfs(int rotulo){
    if(visitados[rotulo] == 0){
        int fim = 1;
        visitados[rotulo] = 1;
        for(int i = 0; i < grafo[chaves[rotulo]].size(); i++){
            cout << grafo[chaves[rotulo]][i] << " " << rotulo << endl;
            if(visitados[grafo[chaves[rotulo]][i]] != 0) {
                fim = 0;
            }
            if(fim == 0){
                lista2.push_back(chaves[rotulo]);
                break;
            }
        }
        cout << "fim " << fim << endl;
        if(fim == 1){
            visitados[rotulo] = 0;
            lista2.push_back(rotulo);
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
        chaves.resize(N-1,0);
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
            chaves[chave-1] = i;
        }
        for(int i = 0; i < N; i++){
            cout << "[";
            for(int j = 0; j < grafo[i].size(); j++){
                cout << grafo[i][j] << " ";
            }
            cout << "] ";
        }
        cout << endl;

        for(int i = 0; i < N-1; i++){
            cout << chaves[i] << " ";
        }
        cout << endl;
        lista.push_back(0);
        for(int i = 0; i < grafo[0].size(); i++){
            lista.push_back(grafo[0][i]);
        }
        while (true){
            for(int i = 0; i < lista.size(); i = 0){
                bfs(lista[lista.size()-1]);
                if(!lista.empty()){
                    lista.pop_back();
                }
            }
            if(lista.empty() && lista2.empty()){
                break;
            }
            for(int i = 0; i < lista2.size(); i++){
                lista.push_back(lista2[i]);
            }
            lista2.clear();
        }

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
