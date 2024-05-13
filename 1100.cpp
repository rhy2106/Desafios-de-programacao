// 8| 7 15 23 31 39 47 55 63
// 7| 6 14 22 30 38 46 54 62
// 6| 5 13 21 29 37 45 53 61
// 5| 4 12 20 28 36 44 52 60
// 4| 3 11 19 27 35 43 51 59
// 3| 2 10 18 26 34 42 50 58
// 2| 1  9 17 25 33 41 49 57
// 1| 0  8 16 24 32 40 48 56
//   a  b  c  d  e  f  g  h 
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> grafo;
vector<int> visitados;
stack<int> lista;
stack<int> lista2;

void bfs(int rotulo, int fim){
    visitados[rotulo] = 1;
    if(rotulo == fim){
        while(!lista.empty()){
            lista.pop();
        }
        while(!lista2.empty()){
            lista2.pop();
        }
    } else{
        for(int i = 0; i < grafo[rotulo].size(); i++){
            if(visitados[grafo[rotulo][i]] == 0){
                lista2.push(grafo[rotulo][i]);
            }
        }
    }
}

void andar(pair<int,int> n1){
    if(n1.second - 2 >= 0 && n1.first/8 - 1 >= 0){
        grafo[n1.first + n1.second].push_back(n1.first + n1.second - 10);
    }
    if(n1.second + 2 < 8 && n1.first/8 - 1 >= 0){
        grafo[n1.first + n1.second].push_back(n1.first + n1.second - 6);
    }
    if(n1.second - 1 >= 0 && n1.first/8 - 2 >= 0){
        grafo[n1.first + n1.second].push_back(n1.first + n1.second - 17);
    }
    if(n1.second + 1 < 8 && n1.first/8 - 2 >= 0){
        grafo[n1.first + n1.second].push_back(n1.first + n1.second - 15);
    }

    if(n1.second - 2 >= 0 && n1.first/8 + 1 < 8){
        grafo[n1.first + n1.second].push_back(n1.first + n1.second + 6);
    }
    if(n1.second + 2 < 8 && n1.first/8 + 1 < 8){
        grafo[n1.first + n1.second].push_back(n1.first + n1.second + 10);
    }
    if(n1.second - 1 >= 0 && n1.first/8 + 2 < 8){
        grafo[n1.first + n1.second].push_back(n1.first + n1.second + 15);
    }
    if(n1.second + 1 < 8 && n1.first/8 + 2 < 8){
        grafo[n1.first + n1.second].push_back(n1.first + n1.second + 17);
    }
}

int main() {
    while(!lista.empty()){
        lista.pop();
    }
    while(!lista2.empty()){
        lista2.pop();
    }
    grafo.resize(64);
    string p1, p2;
    for(int i = 0; i < 64; i++){
        int tmp = i / 8;
        p1 = "";
        p1 += (char)(97+tmp);
        tmp = i % 8;
        p1 += (char)(49+tmp);
        pair<int,int> n1 = make_pair(((int)p1[0]-97)*8,((int)p1[1]-49));
        andar(n1);
    }

    while(cin >> p1 >> p2){
        visitados.clear();
        visitados.resize(64,0);
        int cont = -1;
        cout << "To get from " << p1 << " to " << p2 << " takes ";
        pair<int,int> n1 = make_pair(((int)p1[0]-97)*8,((int)p1[1]-49));
        pair<int,int> n2 = make_pair(((int)p2[0]-97)*8,((int)p2[1]-49));
        int fim = n2.first + n2.second;
        lista.push(n1.first + n1.second);
        while(true){
            cont++;
            while(!lista.empty()){
                bfs(lista.top(),fim);
                if(!lista.empty()){
                    lista.pop();
                }
            }
            if(lista2.empty() && lista.empty()){
                break;
            }
            while(!lista2.empty()){
                lista.push(lista2.top());
                lista2.pop();
            }
        }
        cout << cont << " knight moves." << endl;
    }
    return 0;
}
