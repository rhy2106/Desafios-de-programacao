#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define f first
#define s second
#define iTuple tuple<int,int,int>
#define iicTuple tuple<int,int,char>
#define iPair pair<double,double>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >
#define tqueue priority_queue<iicTuple, vector<iicTuple>, greater<iicTuple> >

using namespace std;

vector<vector<int>> grafo;
vector<int> visitados;

int dentro(int x, vector<int> aresta){
    for(int i = 0; i < aresta.size(); i++) if(x == aresta[i]) return 1;
    return 0;
}

void bfs(int rotulo, int N){
    queue<int> fila;
    fila.push(rotulo);
    while(!fila.empty()){
        int pacote = fila.front();
        fila.pop();
        if(visitados[pacote]) continue;
        visitados[pacote] = 1;
        for(int i = 0; i < N; i++){
            if(!dentro(i,grafo[pacote]) && !visitados[i]) fila.push(i);
        }
    }
}

int main(){
    _;
    int Z;
    cin >> Z;
    for(int z = 0; z < Z; z++){    
        int N, V, cont = 0;
        cin >> N >> V;
        grafo.assign(N,vector<int>());
        visitados.assign(N,0);
        for(int i = 0; i < V; i++){
            int x,y;
            cin >> x >> y;
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }
        for(int i = 0; i < grafo.size(); i++){
            grafo[i].push_back(i);
        }
        for(int i = 0; i < N; i++){
            if(!visitados[i]){
                bfs(i,N);
                cont++;
            }
        }
        
        cout << cont-1<< endl;
    }
    return 0;
}
