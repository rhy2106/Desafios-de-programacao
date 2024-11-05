#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>

using namespace std;

vector<set<int>> grafo;
vector<int> visitados;
set<int> b1;
set<int> b2;
ll int contador = 0;

void dfs(int com){
    queue<iPair> fila;
    fila.push(mp(com,1));
    while(!fila.empty()){
        iPair rotulo = fila.front();
        fila.pop();
        if(rotulo.s%2) b1.insert(rotulo.f);
        else b2.insert(rotulo.f);
        visitados[rotulo.f] = 1;
        for(int i : grafo[rotulo.f]) if(!visitados[i]) fila.push(mp(i,rotulo.s+1));
    }
}

int main(){
    time_t inicio,fim;
    time(&inicio);
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _; int N; cin >> N;
    contador = 0;
    grafo.assign(N,set<int>());
    visitados.assign(N,0);
    b1.clear();
    b2.clear();
    for(int i = 0; i < N-1; i++){
        int x, y; cin >> x >> y;
        grafo[x-1].insert(y-1);
        grafo[y-1].insert(x-1);
    }
    dfs(0);
    contador = b2.size() * b1.size();
    for(int i : b1) contador -= grafo[i].size();
    cout << contador << endl;
    time(&fim);
    cerr << fim - inicio << " segundos" << endl;
    return 0;
}
