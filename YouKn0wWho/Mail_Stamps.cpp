#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>

using namespace std;

map<int,vector<int>> grafo;
set<int> visitados;

void dfs(int rotulo){
    cout << rotulo << " ";
    visitados.insert(rotulo);
    for(int item : grafo[rotulo]) if(!visitados.count(item)) dfs(item);
}

int main(){
    // time_t inicio,fim;
    // time(&inicio);
    _; int N; cin >> N;
    grafo.clear();
    visitados.clear();
    for(int i = 0; i < N; i++){
        int x, y; cin >> x >> y;
        visitados.insert(y);
        visitados.insert(x);
        grafo[x].pb(y);
        grafo[y].pb(x);
    }
    int com;
    for(int item : visitados) if(grafo[item].size() < 2) com = item;
    visitados.clear();
    dfs(com);
    cout << endl;
    // time(&fim);
    // cerr << fim - inicio << " segundos" << endl;
    return 0;
}
