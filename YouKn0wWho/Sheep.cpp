#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair>>
#define tupla(y,x) get< x >( y )
#define gcd( x, y )  __gcd( x, y ) 

using namespace std;

vector<vector<int>> grafo;
vector<int> visitados;
vector<char> matriz;

iPair dfs(int rotulo, iPair quant){
    visitados[rotulo] = 1;
    if(matriz[rotulo] == 'k') quant.f++;
    if(matriz[rotulo] == 'v') quant.s++;
    for(int i : grafo[rotulo]) if(!visitados[i]) quant = dfs(i, quant);
    return quant;
}

int main(){
    time_t inicio,fim;
    time(&inicio);
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _; int N, M; cin >> N >> M;
    grafo.assign(N*M,vector<int>());
    visitados.assign(N*M,0);
    matriz.assign(N*M,' ');
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        for(int j = 0; j < M; j++) matriz[i*M + j] = s[j];
    }
    for(int i = 0; i < N*M; i++){
        if(matriz[i] == '#') visitados[i] = 1;
        if(i%M < M-1) grafo[i].pb(i+1);
        if(i%M > 0  ) grafo[i].pb(i-1);
        if(i+M < N*M) grafo[i].pb(i+M);
        if(i-M > 0  ) grafo[i].pb(i-M);
    }
    iPair vivo = mp(0,0);
    for(int i = 0; i < N*M; i++){
        if(!visitados[i]){
            iPair tmp = mp(0,0);
            tmp = dfs(i,tmp);
            if(tmp.f > tmp.s) vivo.f += tmp.f;
            else vivo.s += tmp.s;
        }
    }
    cout << vivo.f << " " << vivo.s << endl;
    time(&fim);
    cerr << fim - inicio << " segundos" << endl;
    return 0;
}