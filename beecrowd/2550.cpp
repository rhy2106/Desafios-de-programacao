#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define f first
#define s second
#define iPair pair<double,double>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

vector<vector<int>> grafo;
vector<int> visitados;
vector<int> id, floresta;

int find(int x){
    return (id[x] = (id[x] == x ? x : find(id[x])));
}

void unir(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(floresta[x] > floresta[y]) swap(x,y);
    id[x] = y;
    floresta[y] += floresta[x];
}

void bfs(){
    queue<int> fila;
    fila.push(0);
    while(!fila.empty()){
        int pacote = fila.front();
        fila.pop();
        if(visitados[pacote]) continue;
        visitados[pacote] = 1;
        for(int item : grafo[pacote]){
            if(!visitados[item]) fila.push(item);
        }
    }
}


int main(){
    _;
    int N, M;
    while(cin >> N >> M){
        vector<tuple<int,int,int>> arestas;
        floresta.assign(N,1);
        id = vector<int> (N);
        iota(id.begin(),id.end(),0);
        grafo.assign(N,vector<int>());
        visitados.assign(N,0);
        bool possibilidade = false;
        for(int i = 0; i < M; i++){
            int x,y,p;
            cin >> x >> y >> p;
            grafo[x-1].push_back(y-1);
            arestas.emplace_back(p,x-1,y-1);
        }
        bfs();
        for(int i = 0; i < visitados.size(); i++){
            if(!visitados[i]) break;
            if(visitados[i] && i == visitados.size()-1) possibilidade = true; 
        }
        if(possibilidade){
            int cont = 0;
            sort(arestas.begin(),arestas.end());
            for(auto item : arestas){
                if(find(get<1>(item)) != find(get<2>(item))){
                    unir(get<1>(item),get<2>(item));
                    cont += get<0>(item);
                }
            }
            cout << cont << endl;
        } else cout << "impossivel" << endl;
    }
   return 0;
}