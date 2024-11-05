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
int N, M;

void dfs(int rotulo, int fim){
    visitados[rotulo] = 1;
    for(int i : grafo[rotulo]){
        if(rotulo == fim && !visitados[i]) visitados[fim] = 2;
        if(visitados[i] && i == fim) visitados[fim] = 2;
        if(visitados[fim] == 2) return;
        if(!visitados[i]) dfs(i, fim);
    }
}

int main(){
    time_t inicio,fim;
    time(&inicio);
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);

    _; cin >> N >> M;
    vector<char> lab;
    lab.assign(N*M,'.');
    visitados.assign(N*M,0);
    grafo.assign(N*M,vector<int>());
    for(int i = 0; i < N; i++){
        string linha; cin >> linha;
        for(int j = 0; j < M; j++) lab[i*M + j] = linha[j];
    }
    
    for(int i = 0; i < N*M; i++){
        if(lab[i] == 'X') visitados[i] = 1;
        if(i%M < M-1) grafo[i].pb(i+1);
        if(i%M > 0) grafo[i].pb(i-1);
        if(i+M < M*N) grafo[i].pb(i+M);
        if(i-M >= 0) grafo[i].pb(i-M);
    }
    int x, y, z, w; cin >> x >> y >> z >> w;
    int pi = (x-1)*M + (y-1);
    int pf = (z-1)*M + (w-1);
    dfs(pi,pf);
    if(visitados[pf] == 2) cout << "YES" << endl;
    else cout << "NO" << endl;

    time(&fim);
    cerr << fim - inicio << " segundos" << endl;
    return 0;
}
