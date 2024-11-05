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
vector<int> custo;
void dfs(int rotulo, int cont, int ant){
    if(rotulo == 0 && ant != 0){
        custo.pb(cont);
        return;
    }
    visitados[rotulo] = 1;
    for(iPair item : grafo[rotulo]){
        if(!visitados[item.f] || (item.f == 0 && ant != 0)) dfs(item.f, cont + item.s, rotulo);
        if(rotulo == 0) for(int i = 1; i < visitados.size(); i++) visitados[i] = 0;
    }
}

int main(){
    _; int N; cin >> N;
    visitados.assign(N,0);
    grafo.assign(N,vector<iPair>());
    custo.clear();
    for(int i = 0; i < N; i++){
        int x, y, c;
        cin >> x >> y >> c;
        grafo[x-1].pb(mp(y-1,0));
        grafo[y-1].pb(mp(x-1,c));
    }
    dfs(0,0,0);
    int preco = custo[0] > custo[1] ? custo[1] : custo[0];
    cout << preco << endl;
    return 0;
}
