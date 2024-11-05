#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define f first
#define s second
#define iPair pair<int,int>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

vector< vector<iPair> > grafo;
vector<int> distMin;
vector<int> visitados;

void bfs(int fim){
    pqueue fila;
    fila.push(mp(0,0));
    while(!fila.empty()){
        iPair pacote = fila.top();
        fila.pop();
        if(pacote.f < distMin[pacote.s]) distMin[pacote.s] = pacote.f;
        else if(visitados[pacote.s]) continue;
        visitados[pacote.s] = 1;
        for(int i = 0 ; i < grafo[pacote.s].size(); i++){
            int rotulo = grafo[pacote.s][i].f;
            for(int j = 0; j < grafo[rotulo].size(); j++){
				int p = pacote.f + grafo[pacote.s][i].s + grafo[rotulo][j].s;
				if(!visitados[grafo[rotulo][j].f]) fila.push(mp(p,grafo[rotulo][j].f));
			}
        }
    }
}

int main(){
    _;
    vector< tuple<int,int,int> > arestas;
    int C, V;
    cin >> C >> V;
    grafo.assign(C,vector<iPair>());
    distMin.assign(C,999999);
    visitados.assign(C,0);
    for(int i = 0 ; i < V; i++){
        int x,y,d; cin >> x >> y >> d;
        grafo[x-1].push_back(mp(y-1,d));
        grafo[y-1].push_back(mp(x-1,d));
    }
    bfs(C-1);
    if(visitados[C-1]) cout << distMin[C-1] << endl;
    else cout << -1 << endl;
    return 0;
}
