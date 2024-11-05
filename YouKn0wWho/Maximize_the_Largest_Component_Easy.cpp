#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>

using namespace std;


vector<int> id, floresta, visitados;
vector<vector<int>> grafo;
vector<char> matriz;
int N, M, cont = 0;

int find(int x){
    return id[x] = x == id[x] ? x : find(id[x]);
}

void unir(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(floresta[x] > floresta[y]) swap(x,y);
    id[x] = y;
    floresta[y] += floresta[x];
}

void dfs(int rotulo){
    visitados[rotulo] = 1;
    cont++;

    for(int i : grafo[rotulo]){
        if(!visitados[i] && matriz[i] == '#'){
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
    
    _; int t; cin >> t;
    for(int z = 0; z < t; z++){
        cin >> N >> M;
        vector<set<int>> total(N+M);
        grafo.assign(N*M,vector<int>());
        visitados.assign(N*M,0);
        floresta.assign(N*M,1);
        matriz.assign(N*M,'0');
        id = visitados;
        iota(id.begin(),id.end(),0);
        for(int i = 0; i < N; i++){
            string linha; cin >> linha;
            for(int j = 0; j < M; j++) matriz[i*M + j] = linha[j];
        }
        
        for(int i = 0; i < N*M; i++){
            if(i%M < M-1) grafo[i].pb(i+1);
            if(i%M > 0) grafo[i].pb(i-1);
            if(i+M < M*N) grafo[i].pb(i+M);
            if(i - M >= 0) grafo[i].pb(i-M);
        }
        for(int i = 0; i < N*M; i++) if(!visitados[i] && matriz[i] == '#') dfs(i);

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                int num = find(i*M+j);
                if(floresta[num] == 1){
                    for(int item : grafo[i*M+j]){
                        if(matriz[item] == '#'){
                            total[N+j].insert(find(item));
                            total[i].insert(find(item));
                        }
                    }
                }
                total[N+j].insert(num);
                total[i].insert(num);
            }
        }

        int maior = 0;
        for(int i = 0; i < N+M; i++){
            int tmp = 0;
            for(int item : total[i]) tmp += floresta[item];
            if(maior < tmp) maior = tmp;
        }
        
        cout << maior << endl;
    }    
    
    time(&fim);
    cerr << fim - inicio << " segundos" << endl;
    return 0;
}
