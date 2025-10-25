#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set
#define umap unordered_map
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9 + 7;

using namespace std;

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
    _;
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> la(n), lg(n);
		vector<string> gen(n), aut(n);
		umap<string,vector<int>> agrafo;
		umap<string,vector<int>> ggrafo;
		for(int i = 0; i < n; i++){
			string x, y; cin >> x >> y;
			ggrafo[x].pb(i);
			agrafo[y].pb(i);
			gen[i] = x;
			aut[i] = y;
		}
		vector<uset<int>> grafo(n);
		for(int i = 0; i < n; i++){
			for(int v : agrafo[aut[i]]) grafo[i].insert(v);
			for(int v : ggrafo[gen[i]]) grafo[i].insert(v);
		}
		int full = ( 1 << n );
		vector<vector<int>> dp(full,vector<int>(n,0));
		for(int i = 0; i < n; i++) dp[(1 << i)][i] = 1;
		for(int mask = 0; mask < full; mask++){ // 2 ** 16 = 1024 * 64
			for(int i = 0; i < n; i++){ // 16
				if(!(mask & (1 << i))) continue;
				if(!dp[mask][i]) continue;
				for(int v : grafo[i]){ 
					if(mask & (1 << v)) continue;
					int nmask = mask | (1 << v);
					dp[nmask][v] = 1;
				}
			}
		}
		int maior = 0;
		for(int mask = 0; mask < full; mask++)
			for(int j = 0; j < n; j++)
			if(dp[mask][j]) maior = max(maior,__builtin_popcount(mask));
		cout << n - maior << endl;
		
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
