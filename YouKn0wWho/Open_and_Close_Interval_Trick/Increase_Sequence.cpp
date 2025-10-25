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
	ll n, h; cin >> n >> h;
	vector<ll> a(n+1,0);
	for(ll i = 1; i <= n; i++) cin >> a[i];
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
	dp[1][0] = (a[1] == h || a[1] + 1 == h ? 1 : 0);
	dp[1][1] = (a[1] + 1 == h ? 1 : 0);
	for(ll i = 2; i <= n; i++){
		for(ll open = max(0ll,h-a[i]-1); open <= min(h-a[i],i); open++){
			if(a[i] + open == h){
				dp[i][open] = (dp[i][open] + dp[i-1][open])%MOD;
				if(open > 0) dp[i][open] = (dp[i][open] + dp[i-1][open-1])%MOD;
          	}
			if(open + a[i] + 1 == h){
				dp[i][open] = (dp[i][open] + dp[i-1][open+1] * (open + 1))%MOD;
				dp[i][open] = (dp[i][open] + dp[i-1][open])%MOD;
				dp[i][open] = (dp[i][open] + dp[i-1][open]*open)%MOD;
			}
		}
	}
	cout << dp[n][0] << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

