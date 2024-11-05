#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define f first
#define s second
#define iPair pair<int,int>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

vector< vector<iPair> > grafo;
vector<int> visitados;
vector<int> quantMin;

void bfs(int inicio, int fim){
    pqueue fila;
    fila.push(mp(0,inicio));
    while(!fila.empty()){
        iPair pacote = fila.top();
        fila.pop();
        if(visitados[pacote.s]) continue; 
        if(pacote.f < quantMin[pacote.s]) quantMin[pacote.s] = pacote.f;
        visitados[pacote.s] = 1;
        if(pacote.s == fim) return;
        for(int i = 0; i < grafo[pacote.s].size(); i++){
            int p = grafo[pacote.s][i].s;
            if(!visitados[grafo[pacote.s][i].f]) fila.push(mp(p, grafo[pacote.s][i].f));
        }
    }
}

int main(){
    _;
    int N, M, K = 0;
    while(cin >> N >> M, N != 0 || M != 0){
        grafo.assign(N,vector<iPair>());
        int A, inicio, fim;
        K++;
        cout << "Instancia " << K << endl;
        for(int i = 0; i < M; i++){
            int x, y, p;
            cin >> x >> y >> p;
            grafo[x-1].push_back(mp(y-1,p));
            grafo[y-1].push_back(mp(x-1,p));
        }
        cin >> A;
        for(int i = 0; i < A; i++){
            cin >> inicio >> fim;
            quantMin.assign(N,999999);
            visitados.assign(N,0);
            bfs(inicio-1,fim - 1);
            int maior = -999999;
            for(int j = 0; j < N; j++){
                if(j == inicio-1) continue;
                if(visitados[j] && maior < quantMin[j] && quantMin[j] != 999999) maior = quantMin[j];
            }
            if(maior == -999999) maior = 0;
            cout << maior << endl;
        }
        cout << endl;
    }
    return 0;
}