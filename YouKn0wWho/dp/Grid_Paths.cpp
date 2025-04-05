#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set<int>
#define umap unordered_map<int,vector<int>>
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

vector<char> matriz;
vector<int> visitados; 
vector<int> dp;

bool andar(int p, int i, int N){
    int lugar = p + i;
    if(lugar > N*N) return false;
    if(i == 1 && lugar % N == 0 ) return false;
    if(matriz[p + i] == '*') return false;
    return true;
}

void bfs(int N){
    queue<int> fila;
    if(matriz[0] != '*'){
        fila.push(0);
        dp[0] = 1;
    }
    while(!fila.empty()){
        int pacote = fila.front();
        fila.pop();
        for(int i : {1, N}){
            if(!andar(pacote,i,N)) continue;
            dp[pacote + i] = (dp[pacote+i] + dp[pacote]) % 1000000007;
            if(!visitados[pacote+i]) fila.push(pacote+i);
            visitados[pacote+i] = 1;
        }
    }
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
    _; int N; cin >> N;
    matriz.assign(N*N,'.');
    visitados.assign(N*N,0);
    dp.assign(N*N,0);
    for(int i = 0; i < N; i++){
        string tmp; cin >> tmp;
        for(int j = 0; j < N; j++)
            matriz[i*N + j] = tmp[j];
    }
    bfs(N);
    cout << dp[N*N-1] << endl;
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
