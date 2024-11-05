#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>

using namespace std;

vector<vector<int>> grafo;
vector<int> visitados;
map<int,int> alice;
map<int,int> bob;

void dfs(int rotulo, int cont, int inicio){
    cont++;
    if(inicio) bob[rotulo] = cont;
    else alice[rotulo] = cont;
    visitados[rotulo] = 1;
    for(int i : grafo[rotulo]) if(!visitados[i]) dfs(i,cont,inicio);
}

int main(){
    // time_t inicio,fim;
    // time(&inicio);
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _; int N, M; cin >> N >> M;
    grafo.assign(N,vector<int>());
    visitados.assign(N,0);
    alice.clear();
    set<int> num;
    bob.clear();
    for(int i = 0; i < N-1; i++){
        int x, y; cin >> x >> y;
        grafo[x-1].pb(y-1);
        grafo[y-1].pb(x-1);
        num.insert(x-1);
        num.insert(y-1);
    }
    dfs(0,-1,0);
    visitados.assign(N,0);
    int cont = 0;
    dfs(M-1,-1,1);
    for(int c : num) if(bob.count(c) && alice[c] > bob[c] && alice[c] > cont) cont = alice[c];
    cout << cont*2 << endl;
    // time(&fim);
    // cerr << fim - inicio << " segundos" << endl;
    return 0;
}
