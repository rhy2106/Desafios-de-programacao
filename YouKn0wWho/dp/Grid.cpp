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
#define gcd( x, y )  __gcd( x, y ) // menor divisor comum
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;
const ll int MOD = 1000000007;
using namespace std;

int main() {
    clock_t tinicio, tfim;
    tinicio = clock();
    _; int N, M; cin >> N >> M;
	vector<char> matriz;
	vector<int> dp;
	dp.assign(N*M, 0);
	matriz.assign(N*M, '.');
	dp[0] = 1;
	for(int i = 0; i < N; i++){
		string l; cin >> l;
		for(int j = 0; j < M; j++)
			matriz[i*M + j] = l[j];
	}
	queue<int> fila;
	fila.push(0);
	while(!fila.empty()){
		int pacote = fila.front();
		fila.pop();
		for(int i : {1, M}){
			if(i == 1 && (pacote + i) % M == 0) continue;
			if(pacote + i >= M*N) continue;
			int prox = pacote + i;
			if(matriz[prox] == '#') continue;
			if(dp[prox] == 0) fila.push(prox);
			dp[prox] = (dp[prox] + dp[pacote]) % MOD;
		}
	}
    cout << dp[N*M-1] << endl;
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

