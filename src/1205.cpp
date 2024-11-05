#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define f first
#define s second
#define iPair pair<int,int>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

vector<vector<int>> grafo;
vector<int> visitados;
vector<int> quantMin;
vector<int> soldados;

void bfs(int peso, int inicio){
    pqueue fila;
    fila.push(mp(peso,inicio));
    while(!fila.empty()){
        iPair pacote = fila.top();
        fila.pop();
        if(pacote.f <= quantMin[pacote.s]) quantMin[pacote.s] = pacote.f;
        if(visitados[pacote.s]) continue;
        visitados[pacote.s] = 1;
        for(int i = 0; i < grafo[pacote.s].size(); i++){
            int p = quantMin[pacote.s] + soldados[grafo[pacote.s][i]];
            if(!visitados[grafo[pacote.s][i]]) fila.push(mp(p, grafo[pacote.s][i]));
        }
    }
}

int main(){
    _;
    int N,M,K;
    double P, chance;
    while(cin >> N >> M >> K >> P){
        grafo.assign(N,vector<int>());
        soldados.assign(N,0);
        visitados.assign(N,0);
        quantMin.assign(N,999999);
        int A, inicio, fim;
        for(int i = 0; i < M; i++){
            int x, y;
            cin >> x >> y;
            grafo[x-1].push_back(y-1);
            grafo[y-1].push_back(x-1);
        }
        cin >> A;
        for(int i = 0; i < A; i++){
            int tmp;
            cin >> tmp;
            soldados[tmp-1]++;
        }
        cin >> inicio >> fim;
        bfs(soldados[inicio-1], inicio-1);
        if(quantMin[fim-1] > K) chance = 0;
        else chance = pow(P,quantMin[fim-1]);
        cout << fixed << setprecision(3) << chance << endl;
    }
    return 0;
}
