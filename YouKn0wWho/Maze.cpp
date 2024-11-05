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
vector<char> lab;
map<int,int> visitados;
int N, M;
void dfs(int rotulo,int cont){
    visitados[rotulo] = cont;
    for(int i : grafo[rotulo]) if(!visitados.count(i)) dfs(i, cont+1);
}

int main(){
    // time_t inicio,fim;
    // time(&inicio);
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);

    _; int K; cin >> N >> M >> K;
    grafo.assign(N*M,vector<int>());
    vector<int> caminhos (N*M);
    lab.assign(N*M,'1');
    visitados.clear();
    int c;
    iota(caminhos.begin(),caminhos.end(),0);
    for(int i = 0; i < N; i++){
        string linha; cin >> linha;
        for(int j = 0; j < M; j++) lab[i*M + j] = linha[j];
    }
    
    for(int i = 0; i < N*M; i++){
        if(lab[i] == '.') c = i;
        if(lab[i] == '#') visitados[i] = -1;
        if(i%M < M-1) grafo[i].pb(i+1);
        if(i%M > 0) grafo[i].pb(i-1);
        if(i+M < M*N) grafo[i].pb(i+M);
        if(i - M >= 0) grafo[i].pb(i-M);
    }
    dfs(c,0);
    sort(caminhos.begin(), caminhos.end(), [](const int a, const int b){return visitados[a] > visitados[b];});
    for(int i = 0; i < K; i++) lab[caminhos[i]] = 'X';
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cout << lab[i*M + j];
        cout << endl;
    }
    
    // time(&fim);
    // cerr << fim - inicio << " segundos" << endl;
    return 0;
}
