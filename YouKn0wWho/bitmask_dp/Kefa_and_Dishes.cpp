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
	int n, m, k; cin >> n >> m >> k;
	vector<ll> a(n);
	vector<vector<ll>> s(n,vector<ll>(n,0));
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < k; i++){
		int x, y, w; cin >> x >> y >> w;
		s[x-1][y-1] = w;
	}
	int full = (1 << n);
	vector<vector<ll>> dp(full,vector<ll>(n,-INF));
	vector<ll> ss(full,0);
	for(int i = 0; i < n; i++) dp[(1<<i)][i] = 0;
	for(int mask = 0; mask < full; mask++){
		for(int i = 0; i < n; i++){
			if(!(mask & (1<<i))) continue;
			ss[mask] += a[i];
			for(int v = 0; v < n; v++){
				if(mask & (1<<v)) continue;
				int nmask = mask | (1<<v);
				dp[nmask][v] = max(dp[nmask][v], dp[mask][i] + s[i][v]);
			}
		}
	}
	ll maior = 0;
	for(int mask = 0; mask < full; mask++){
		ll tmp = 0;
		if(__builtin_popcount(mask) > m) continue;
		for(int i = 0; i < n; i++){
			maior = max(maior, ss[mask] + dp[mask][i]);
		}
	}
	cout << maior << endl;
	
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

