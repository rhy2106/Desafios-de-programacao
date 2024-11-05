#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> grafo;
vector<int> visitados;
map<string, int> pessoas;
set<string> convidados;

void bfs(int fim){
    vector<string> fila;
    fila = grafo[0];
    visitados[0] = 1;
    int cont = 0;
    while(!fila.empty()){
        vector<string> fila2;
        for(string name : fila){
            if(!visitados[pessoas[name]]){
                visitados[pessoas[name]] = 1;
                convidados.insert(name);
                for(string n : grafo[pessoas[name]]){
                    fila2.push_back(n);
                }
            }
        }
        cont++;
        fila = fila2;
        if(cont == fim){
            fila.clear();
        }
    }
}

int main(){
    int N, fim;
    cin >> N >> fim;
    convidados.clear();
    pessoas.clear();
    grafo.clear();
    grafo.resize(N+1);
    visitados.clear();
    visitados.resize(N+1,0);
    pessoas["Rerisson"] = 0;
    for(int i = 0; i < N; i++){
        string p1, p2;
        cin >> p1 >> p2;
        if(pessoas.find(p1) == pessoas.end()){
            pessoas[p1] = pessoas.size();
        }
        if(pessoas.find(p2) == pessoas.end()){
            pessoas[p2] = pessoas.size();
        }
        grafo[pessoas[p1]].push_back(p2);
        grafo[pessoas[p2]].push_back(p1);
    }
    bfs(fim);
    cout << convidados.size() << endl;
    for(string nome : convidados){
        cout << nome << endl;
    }
    return 0;
}