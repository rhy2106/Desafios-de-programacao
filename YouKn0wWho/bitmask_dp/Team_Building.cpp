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
	int n, p, k; cin >> n >> p >> k;
	int a[n];
	int b[n][p];
	for(int &i : a) cin >> i;
	for(int i = 0; i < n; i++)
		for(int &j : b[i]) cin >> j;
	
	vector<int> id(n,0);
	iota(id.begin(),id.end(),0);
	sort(id.begin(),id.end(), [&](int i, int j){ return a[i] > a[j];});
	
	int full = ( 1 << p );
	vector<ll> dp(full,-1e18);
	dp[0] = 0;
	for(int t = 0; t < n; t++){
		int x = id[t];
		vector<ll> ndp = dp;
		for(int mask = 0; mask < full; mask++){
			if(dp[mask] < -1e17) continue;
			int j = __builtin_popcount(mask);
			int s = t - j;
			for(int i = 0; i < p; i++){
				if(mask & (1 << i)) continue;
				int nmask = (mask | (1 << i));
				ndp[nmask] = max(dp[mask] + b[x][i], ndp[nmask]);
			}
			if(s < k)
				ndp[mask] = max(ndp[mask], dp[mask] + a[x]);
		}
		dp.swap(ndp);
	}
	cout << dp[full-1] << endl;

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

