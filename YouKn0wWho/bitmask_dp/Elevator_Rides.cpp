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
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int full = (1<<n);
	vector<vector<int>> dp(full,vector<int>(n+1,INF));
	for(int i = 0 ;i < n; i++) dp[(1<<i)][1] = a[i];
	for(int mask = 0; mask < full; mask++){
		for(int i = 0; i < n; i++){
			if(mask & (1<<i)) continue;
			int nmask = mask | (1<<i);
			for(int j = n-1; j > 0; j--){
				if(dp[mask][j] == INF) continue;
				if(dp[mask][j] + a[i] <= k) dp[nmask][j] = min(dp[nmask][j],dp[mask][j] + a[i]);
				else dp[nmask][j+1] = min(dp[nmask][j+1], min(dp[mask][j],a[i]));
			}
		}
	}
	int menor = n;
	for(int i = n; i > 0; i--) if(dp[full-1][i] != INF) menor = i;
	cout << menor << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

