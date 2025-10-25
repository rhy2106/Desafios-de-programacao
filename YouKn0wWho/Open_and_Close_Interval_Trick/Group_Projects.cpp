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
	int n, K; cin >> n >> K;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(),a.end());
	vector<vector<int>> dp(K+1,vector<int>(n+1,0));
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		ll diff = (i == 0 ? 0 : a[i] - a[i-1]);
		vector<vector<int>> ndp(K+1,vector<int>(n+1,0));
		for(int k = 0; k <= K; k++){
			for(int j = 0; j < n; j++){
				int v = dp[k][j];
				if(!v) continue;
				int nk = k + j * diff;
				if(nk > K) continue;
				ndp[nk][j] = (ndp[nk][j] + v)%MOD;
				if(j > 0) ndp[nk][j] = (ndp[nk][j] + 1ll*v*j)%MOD;
				ndp[nk][j+1] = (ndp[nk][j+1] + v)%MOD;
				if(j > 0) ndp[nk][j-1] = (ndp[nk][j-1] + 1ll*v*j)%MOD;
			}
		}
		dp.swap(ndp);
	}
	ll total = 0;
	for(int k = 0; k <= K; k++)
		total = (total + dp[k][0])%MOD;
	cout << total << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

