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
vector<double> raio;
vector<int> visitados;
vector<double> quantMin;

void bfs(int inicio){
    pqueue fila;
    fila.push(mp(0,inicio));
    while(!fila.empty()){
        iPair pacote = fila.top();
        fila.pop();
        if(visitados[pacote.s]) continue;
        if(pacote.f < quantMin[pacote.s]) quantMin[pacote.s] = pacote.f;
        visitados[pacote.s] = 1;
        for(int i = 0; i < grafo[pacote.s].size(); i++){
            double p = quantMin[pacote.s] + grafo[pacote.s][i].s;
            if(!visitados[grafo[pacote.s][i].f]) fila.push(mp(p,grafo[pacote.s][i].f));
        }
    }
}

void mostrar(){
    cout <<  "Grafo:" << endl;
    for(int i = 0; i < grafo.size(); i++){
        cout << "[";
        for(int j = 0; j < grafo[i].size(); j++){
            cout << "[" << grafo[i][j].f << "," << grafo[i][j].s << "]";
        }
        cout << "]" << endl;
    }
    cout << endl;
}
void mostrar2(){
    cout << "Posicao:" << endl;
    for(int i = 0; i < posicao.size(); i++){
        cout << "[" << posicao[i].f << "," << posicao[i].s << "]";
    }
    cout << endl;
}
void mostrar3(){
    cout << "Raio:" << endl;
    for(int i = 0; i < raio.size(); i++){
        cout << "[" << raio[i] << "]";
    }
    cout << endl;
}

int main(){
    _;
    int N, C;
    while(cin >> N, N != 0){
        grafo.assign(N,vector<iPair>());
        posicao.assign(N,iPair ());
        raio.assign(N,0);
        for(int i = 0; i < N; i++){
            int x,y,r;
            cin >> x >> y >> r;
            posicao[i] = mp(x,y);
            raio[i] = r;
        }

        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                if(j == i) continue;
                double dist;
                int xa = posicao[i].f, ya = posicao[i].s, xb = posicao[j].f, yb = posicao[j].s;
                if(xa == xb) dist = ya - yb;
                else if(ya == yb) dist = xa - xb;
                else dist = sqrt(pow(xa - xb,2) + pow(ya - yb,2));
                if(dist < 0) dist *= -1;
                if(dist <= raio[i]) grafo[i].push_back(mp(j,dist));
                if(dist <= raio[j]) grafo[j].push_back(mp(i,dist));
            }
        }
        cin >> C;
        for(int i = 0; i < C; i++){
            int x, y;
            cin >> x >> y;
            visitados.assign(N,0);
            quantMin.assign(N,999999);
            bfs(x-1);
            if(visitados[y-1]) cout << (int)quantMin[y-1] << endl;
            else cout << -1 << endl;
        }
    }
   return 0;
}
