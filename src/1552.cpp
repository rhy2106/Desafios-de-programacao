#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define f first
#define s second
#define iPair pair<double,double>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

vector< vector<iPair> > grafo;
vector<iPair> posicao;
vector<int> visitados;
vector<double> quantMin;

void bfs(){
    pqueue fila;
    fila.push(mp(0,0));
    while(!fila.empty()){
        iPair pacote = fila.top();
        fila.pop();
        if(visitados[pacote.s]) continue; 
        if(pacote.f < quantMin[pacote.s]) quantMin[pacote.s] = pacote.f;
        visitados[pacote.s] = 1;
        for(int i = 0; i < grafo[pacote.s].size(); i++){
            double p = grafo[pacote.s][i].s;
            if(!visitados[grafo[pacote.s][i].f]) fila.push(mp(p, grafo[pacote.s][i].f));
        }
    }
}

void mostrar(){
    for(int i = 0; i < quantMin.size(); i++){
        cout << "["<< quantMin[i] << "]";
    }
    cout << endl;
}

int main(){
    _;
    int C;
    cin >> C;
    for(int z = 0; z < C; z++){
        int N;
        cin >> N;
        grafo.assign(N,vector<iPair>());
        visitados.assign(N,0);
        quantMin.assign(N,999999);
        posicao.resize(N);
        for(int i = 0; i < N; i++){
            int x, y;
            cin >> x >> y;
            posicao[i] = mp(x,y);
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(j == i) continue;
                double dist;
                int xa = posicao[i].f, ya = posicao[i].s, xb = posicao[j].f, yb = posicao[j].s;
                if(xb > xa) swap(xa,xb);
                if(yb > ya) swap(ya,yb);
                if(xa == xb) dist = ya - yb;
                else if(ya == yb) dist = xa - xb;
                else dist = sqrt(pow(xa - xb,2) + pow(ya - yb,2)); 
                grafo[i].push_back(mp(j,dist));
            }
        }
        bfs();
        double maior = 0;
        for(int i = 0; i < quantMin.size(); i++){
            maior += quantMin[i];
        }
        maior = maior/100;
        cout << fixed << setprecision(2) << maior << endl;
    }
    return 0;
}