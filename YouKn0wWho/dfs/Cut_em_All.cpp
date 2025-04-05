#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>
#define pqueue priority_queue<int,vector<int>, greater<int>>

using namespace std;

vector<vector<int>> grafo;
vector<int> visitados;
int contador;

int dfs(int rotulo){
    int cont = 1, cont2 = 0;
    visitados[rotulo] = 1;
    for(int item : grafo[rotulo]){
        if(!visitados[item]) cont2 = dfs(item);
        if(cont2 != 0 && cont2 % 2 == 0) contador++;
        else cont += cont2;
        cont2 = 0;
    }
    return cont;
}
int main(){
    time_t inicio,fim;
    time(&inicio);
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    
    _; int N; cin >> N;
    grafo.assign(N,vector<int>());
    visitados.assign(N,0);
    contador = 0;
    for(int i = 0; i < N-1; i++){
        int x, y; cin >> x >> y;
        grafo[x-1].pb(y-1);
        grafo[y-1].pb(x-1);
    }
    if(N%2){
        cout << -1 << endl;
        return 0;
    }
    dfs(0);
    cout << contador << endl;
    time(&fim);
    cerr << fim - inicio << " segundos" << endl;
    return 0;
}
