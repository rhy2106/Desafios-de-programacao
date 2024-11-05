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
    int N,M;
    vector<iTuple> arestas;
    cin >> N >> M;
    id = vector<int> (N);
    floresta.assign(N,1);
    iota(id.begin(),id.end(),0);
    cin >> N;
    for(int i = 0; i < M; i++){
        int x,y,p;
        cin >> x >> y >> p;
        arestas.emplace_back(p,x-1,y-1);
    }
    int dist = 0;
    sort(arestas.begin(),arestas.end());
    for(auto item : arestas){
        if(find(get<1>(item)) != find(get<2>(item))){
            unir(get<1>(item),get<2>(item));
            dist += get<0>(item);
        }
    }
    cout << dist*2 << endl;
    return 0;
}