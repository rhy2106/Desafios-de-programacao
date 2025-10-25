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
	int n, m; cin >> n >> m;
	vector<int> g(n,0);
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		a--; b--;
		g[a] |= (1<<b);
		g[b] |= (1<<a);
	}
	vector<int> dp((1<<n), INF);
	dp[0] = 1;
	for(int b = 0; b < n; b++){
		for(int mask = 0; mask < (1<<n); mask++){
			if(dp[mask] == 1 && (g[b] & mask) == mask) dp[mask | (1<<b)] = 1;
		}
	}
	for(int mask = 1; mask < (1<<n); mask++){
		for(int nmask = mask; --nmask &= mask;){
			dp[mask] = min(dp[mask], dp[nmask] + dp[mask^nmask]);
		}
	}
	cout << dp.back() << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

