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
vector<int> tempMin;

void bfs(int rotulo, int nao){
    pqueue fila;
    fila.push(mp(0,rotulo));
    while(!fila.empty()){
        iPair pacote = fila.top();
        fila.pop();
        if(visitados[pacote.s]) continue;
        tempMin[pacote.s] = pacote.f;
        visitados[pacote.s] = 1;
        for(int i = 0; i < grafo[pacote.s].size(); i++){
            int p = tempMin[pacote.s] + 1;
            if(!visitados[grafo[pacote.s][i]] && grafo[pacote.s][i] != nao) fila.push(mp(p,grafo[pacote.s][i]));
        }
    }
}

int main(){
    _;
    int N,M;
    while(cin >> N >> M){    
        int comeco, nao, fim;
        grafo.assign(N,vector<int>());
        visitados.assign(N,0);
        tempMin.assign(N,9999999);
        for(int i = 0; i < M; i++){
            int x,y;
            cin >> x >> y;
            grafo[x-1].push_back(y-1);
            grafo[y-1].push_back(x-1);
        }
        cin >> comeco >> fim >> nao;
        bfs(comeco-1,nao-1);
        cout << tempMin[fim-1] << endl;
    }
    return 0;
}
