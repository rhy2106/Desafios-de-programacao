#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set<int>
#define umap unordered_map<int,vector<int>>
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
#define gcd( x, y )  __gcd( x, y ) // menor divisor comum

const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;
const ll int MOD = 998244353;
using namespace std;

int main() {
    clock_t tinicio, tfim;
    tinicio = clock();

    _;
	int N, M = 0; cin >> N;
	vector<vector<int>> dp;
	vector<int> bolas;
	bolas.assign(N+1,0);
	for(int i = 1; i <= N; i++){
		cin >> bolas[i];
		M += bolas[i];
	}
	dp.assign(N+1, vector<int>(M+1,0));
	sort(bolas.begin() + 1, bolas.end());
	dp[0][0] = 1;
	int total = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j <= M; j++){
			if( j >= bolas[i] ) total = ( total + (j + bolas[i] + 1ll) / 2 * dp[i-1][j]) % MOD;
			else total = (total + 1ll * bolas[i] * dp[i-1][j]) % MOD;
			dp[i][j] = dp[i-1][j];
			if (j >= bolas[i]) dp[i][j] = (dp[i][j] + dp[i-1][j-bolas[i]]) % MOD;
		}
	}
	cout << total << endl;
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}



