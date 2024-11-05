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

int dfs(int rotulo, int cont){
    visitados[rotulo] = 1;
    for(int i : grafo[rotulo]) if(!visitados[i]) cont = dfs(i, cont+1);
    return cont;
}

int main(){
    time_t inicio,fim;
    time(&inicio);
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);

    _; int Z; cin >> Z;
    for(int z = 0; z < Z; z++){
        ll int N, M; cin >> N >> M;
        vector<char> matriz(N*M);
        grafo.assign(N*M,vector<int>());
        visitados.assign(N*M,0);
        ll int contador = 0;
        for(int i = 0; i < N; i++){
            string s; cin >> s;
            for(int j = 0; j < M; j++) matriz[i*M + j] = s[j];
        }
        for(int i = 0; i < N*M; i++){
            if(matriz[i] == '~') visitados[i] = 1;
            if(i%M < M-1) grafo[i].pb(i+1);
            if(i%M > 0  ) grafo[i].pb(i-1);
            if(i+M < N*M) grafo[i].pb(i+M);
            if(i-M > 0  ) grafo[i].pb(i-M);
        }
        for(int i = 0; i < N*M; i++){
            if(!visitados[i]){
                ll int tmp = dfs(i,1);
                tmp = pow(tmp,2);
                contador += tmp;
            }
        }
        if(contador % (M*N) == 0) cout << contador/(M*N) << endl;
        else {
            ll x = __gcd(contador,M*N);
            cout << contador/x << " / " << M*N/x << endl;
        }
    }
    time(&fim);
    cerr << fim - inicio << " segundos" << endl;
    return 0;
}