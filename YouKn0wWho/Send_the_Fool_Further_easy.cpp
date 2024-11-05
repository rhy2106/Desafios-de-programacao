#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>

using namespace std;

vector<int> visitados;
vector<vector<iPair>> grafo;
int maior = 0;

void dfs(int rotulo, int cont){
    if(cont > maior) maior = cont;
    visitados[rotulo] = 1;
    for(iPair item : grafo[rotulo]){
        if(!visitados[item.f]) dfs(item.f, cont + item.s);
    }
}

int main(){
    _; int N; cin >> N;
    visitados.assign(N,0);
    grafo.assign(N,vector<iPair>());
    for(int i = 0; i < N-1; i++){
        int x, y, c;
        cin >> x >> y >> c;
        grafo[x].pb(mp(y,c));
        grafo[y].pb(mp(x,c));
    }
    maior = 0;
    dfs(0,0);
    cout << maior << endl;
    return 0;
}
