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
	int n;
	while(cin >> n, n != 0){
		int m; cin >> m;
		vector<ll> a(m+2);
		for(int i = 1; i <= m; i++) cin >> a[i];
		a[0] = 0;
		a[m+1] = n;
		m++;
		vector<vector<ll>> dp(m+1,vector<ll>(m+1,0));
		vector<vector<ll>> opt(m+1,vector<ll>(m+1,0));
		for(int len = 0; len <= m; len++){
			for(int l = 0; l+len <= m; l++){
				int r = l+len;
				if(len < 2){
					dp[l][r] = 0;
					opt[l][r] = l;
					continue;
				}
				int mleft = opt[l][r-1];
				int mright = opt[l+1][r];
				dp[l][r] = 2e18; 
				for(int i = mleft; i <= mright; i++){
					ll cost = dp[l][i] + dp[i][r] + (a[r] - a[l]);
					if(dp[l][r] <= cost) continue;
					dp[l][r] = cost;
					opt[l][r] = i;
				}
			}
		}
		cout << "The minimum cutting is " << dp[0][m] << "." << endl;
		
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

