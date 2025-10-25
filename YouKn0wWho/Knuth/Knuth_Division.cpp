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

const int N = 5005;

ll dp[N][N];
int opt[N][N];
ll p[N];

ll sum(int l, int r){
	return p[r] - p[l-1];
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _; int n; cin >> n;
	vector<int> a(n+1,0);
	p[0] = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], p[i] = p[i-1] + a[i];
	for(int i = 1; i <= n; i++){
		dp[i][i] = 0;
		opt[i][i] = i;
	}
	for(int len = 2; len <= n; len++){
		for(int l = 1; l+len-1 <= n; l++){
			int r = l+len-1;
			dp[l][r] = LLONG_MAX;
			int mleft = opt[l][r-1];
			int mright = opt[l+1][r];
			for (int m = mleft; m <= mright; m++) {
                ll cost = dp[l][m] + dp[m+1][r] + sum(l,r);
                if (cost < dp[l][r]) {
                    dp[l][r] = cost;
                    opt[l][r] = m;
                }
            }
        }
    }

    cout << dp[1][n] << "\n";
	
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

