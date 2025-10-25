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
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n, w; cin >> n >> w;
	vector<vector<int>> a(n);
	for(int i = 0; i < w; i++){
		int x, y; cin >> x >> y;
		x--; y--;
		a[x].pb(y);
	}
	int m = (1 << n);
	vector<vector<ll>> dp(m,vector<ll>(n,0));
	dp[1][0] = 1;
	for(int mask = 0; mask < m; mask++){
		for(int v = 0; v < n; v++){
			if(!(mask & (1<<v))) continue;
			ll atual = dp[mask][v];
			if( atual == 0) continue;
			for(int u : a[v]){
				if(mask & (1<<u)) continue; // já visitado
                int nmask = mask | (1<<u);
                dp[nmask][u] = (dp[nmask][u] + atual) % MOD;
			}
		}
	}

	cout << dp[m-1][n-1] << endl;

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

