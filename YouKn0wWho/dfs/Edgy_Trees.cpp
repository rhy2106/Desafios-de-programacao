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
vector<int> id, floresta;
ll int contador;

int find(int x){
    return id[x] = ( x == id[x] ? x : find(id[x]) );
}

void unir(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(floresta[x] > floresta[y]) swap(x,y);
    floresta[y] += floresta[x];
    id[x] = y;
}

void dfs(int rotulo){
    visitados[rotulo] = 1;
    for(int i : grafo[rotulo]) {
        if(!visitados[i]){
            unir(rotulo,i);
            dfs(i);
        }
    }
}

int main(){
    time_t inicio,fim;
    time(&inicio);
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    
    _; int N, k; cin >> N >> k;

    grafo.assign(N,vector<int>());
    visitados.assign(N,0);
    floresta.assign(N,1);
    id.assign(N,0);
    iota(id.begin(),id.end(),0);
    queue<int> fila;
    ll int modulo = pow(10,9) + 7;
    for(int i = 0; i < N-1; i++){
        int x, y, c; cin >> x >> y >> c;
        if(c) continue;
        grafo[x-1].pb(y-1);
        grafo[y-1].pb(x-1);
    }
    for(int i = 0; i < N; i++){
        if(!visitados[i]){
            fila.push(i);
            dfs(i);
        }
    }
    ll int tmp = 0;
    while(!fila.empty()){
        int pacote = fila.front();
        fila.pop();
        int x = floresta[find(pacote)];
        ll int tmp2 = x;
        for(int i = 0; i < k-1; i++){
            tmp2 *= x;
            tmp2 = tmp2 % modulo;
        }
        tmp += tmp2;
        tmp = tmp % modulo;
    }
    contador = N;
    for(int i = 0; i < k-1; i++){
        contador *= N;
        contador = contador%modulo;
    }
    contador -= tmp;
    if(contador < 0) contador = modulo + contador;
    contador = contador%modulo;
    cout << contador << endl;
    time(&fim);
    cerr << fim - inicio << " segundos" << endl;
    return 0;
}
