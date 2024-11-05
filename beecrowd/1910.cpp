#include <iostream>
#include <vector>

using namespace std;

vector<int> visitados;
int origem, fim;

int bfs(){
    if(origem == fim){
        return 0;
    }
    int cont = 0;
    vector<int> fila;
    fila.push_back(origem);
    while(!fila.empty()){
        vector<int> fila2;
        for(int num : fila){
            if(num == fim) return cont;
            if(visitados[num]) continue;
            visitados[num] = 1;
            if(num+1 <= 100000) fila2.push_back(num+1);
            if(num-1 > 0) fila2.push_back(num-1);
            if(num*2 <= 100000) fila2.push_back(num*2);
            if(num*3 <= 100000) fila2.push_back(num*3);
            if(num%2 == 0) fila2.push_back(num/2);
        }
        fila = fila2;
        cont++;
    }
    return -1;
}

int main(){
    int canais;
    while(cin >> origem >> fim >> canais, origem != 0 || fim != 0 || canais != 0){
        visitados.clear();
        visitados.resize(100001,0);
        for(int i = 0; i < canais; i++){
            int tmp;
            cin >> tmp;
            visitados[tmp] = 1;
        }
        cout << bfs() << endl;
    }
    return 0;
}