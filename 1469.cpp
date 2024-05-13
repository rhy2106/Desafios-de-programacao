#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> grafo;
vector<int> visitados;
vector<int> idades;
int idade = 999999;

void dfs(int rotulo){
    visitados[rotulo] = 1;
    for(int i = 0; i < grafo[rotulo].size(); i++){
        if(visitados[grafo[rotulo][i]] == 0){
            if(idades[grafo[rotulo][i]] < idade){
                idade = idades[grafo[rotulo][i]];
            }
            dfs(grafo[rotulo][i]);
        }
    }
}

int main() {
    int N, M, I;
    cin >> N >> M >> I;
    idade = 999999;
    grafo.clear();
    visitados.clear();
    grafo.resize(N);
    visitados.resize(N,0);
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        idades.push_back(tmp);
    }
    for(int i = 0; i < M; i++){
        int X, Y;
        cin >> X >> Y;
        Y--;
        X--;
        grafo[Y].push_back(X);
    }
    for(int i = 0; i < I; i++){
        idade = 999999;
        visitados.clear();
        visitados.resize(N,0);
        char id;
        cin >> id;

        if( id == 'T'){
            int p1, p2, tmp;
            cin >> p1 >> p2;
            p1--;
            p2--;
            tmp = idades[p1];
            grafo[p1].swap(grafo[p2]);
            idades[p1] = idades[p2];
            idades[p2] = tmp;
        }

        for(int ii = 0; ii < grafo.size(); ii++){
            cout << ii << ": (";
            for(int j = 0; j < grafo[ii].size(); j++){
                cout << grafo[ii][j] << " ";
            }
            cout << "), " << idades[ii] << "; ";
        }
        cout << endl;

        if( id == 'P'){
            int p1;
            cin >> p1;
            p1--;
            dfs(p1);
            if(idade == 999999) {
                cout << "*" << endl;
            } else{
                cout << idade << endl;
            }
        }
    }
    return 0;
}
