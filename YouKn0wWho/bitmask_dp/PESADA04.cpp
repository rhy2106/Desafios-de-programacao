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
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		n++;
		vector<vector<iPair>> a(n);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				int tmp; cin >> tmp;
				a[i].pb(mp(j,tmp));
			}
				
		int m = (1 << n);
		vector<vector<int>> dp(m, vector<int>(n, INF));
		dp[1][0] = 0;
		for(int mask = 1; mask < m; mask++){
			for(int i = 0; i < n; i++){
				if(!(mask & (1<<i))) continue;
				int cost = dp[mask][i];
				for(auto [u,k] : a[i]){
					if( mask & (1<<u) ) continue;
					int nmask = mask | (1<<u);
					dp[nmask][u] = min(dp[nmask][u], cost + k);
				}
			}
		}
		ll menor = INF;
		for(int i = 1; i < n; i++){
			ll tmp = dp[m-1][i] + a[i][0].s;
			menor = min(menor, tmp);
		}
		cout << menor << endl;
		
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

