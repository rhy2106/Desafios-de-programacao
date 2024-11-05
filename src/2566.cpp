#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define f first
#define s second
#define iPair pair<double,double>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

vector<vector<iPair>> grafo1;
vector<vector<iPair>> grafo2;
vector<int> visitados;
vector<int> precoMin;

void bfs(int veiculo){
    vector<vector<iPair>> grafo;
    pqueue fila;
    if(veiculo) grafo = grafo1;
    else grafo = grafo2;
    fila.push(mp(0,0));
    while(!fila.empty()){
        iPair pacote = fila.top();
        fila.pop();
        if(visitados[pacote.s]) continue;
        if(pacote.f < precoMin[pacote.s]) precoMin[pacote.s] = pacote.f;
        visitados[pacote.s] = 1;
        for(int i = 0; i < grafo[pacote.s].size(); i++){
            int p = precoMin[pacote.s] + grafo[pacote.s][i].s;
            if(!visitados[grafo[pacote.s][i].f]) fila.push(mp(p,grafo[pacote.s][i].f));
        }
    }
}

int main(){
    _;
    int N, M;
    while(cin >> N >> M){
        grafo1.assign(N,vector<iPair>());
        grafo2.assign(N,vector<iPair>());
        visitados.assign(N,0);
        precoMin.assign(N,9999999);
        for(int i = 0; i < M; i++){
            int x,y,veiculo,p;
            cin >> x >> y >> veiculo >> p;
            if(veiculo) grafo1[x-1].push_back(mp(y-1,p));
            else grafo2[x-1].push_back(mp(y-1,p));
        }
        bfs(0);
        int menor = precoMin[N-1];
        visitados.assign(N,0);
        precoMin.assign(N,9999999);
        bfs(1);
        if(menor > precoMin[N-1]) menor = precoMin[N-1];
        cout << menor << endl;
    }
   return 0;
}