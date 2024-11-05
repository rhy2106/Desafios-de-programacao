#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define f first
#define s second
#define iPair pair<double,double>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

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

int main(){
    _;
    int N;
    while(cin >> N){
        vector<iPair> posicao (N);
        vector<tuple<double,int,int>> arestas;
        double cont = 0;
        floresta.assign(N,1);
        id = vector<int> (N);
        iota(id.begin(),id.end(),0);
        for(int i = 0; i < N; i++){
            int x, y;
            cin >> x >> y;
            posicao[i] = mp(x,y);
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
                arestas.emplace_back(dist,i,j);
            }
        }
        sort(arestas.begin(),arestas.end());
        for(auto item : arestas){
            if(find(get<1>(item)) != find(get<2>(item))){
                unir(get<1>(item),get<2>(item));
                cont += get<0>(item);
            }
        }
        cout << fixed << setprecision(2) << cont << endl;
    }
    return 0;
}