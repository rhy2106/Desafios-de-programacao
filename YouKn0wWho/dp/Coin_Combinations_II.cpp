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
const ll int MOD = 1e9 + 7;
using namespace std;

int main() {
    clock_t tinicio, tfim;
    tinicio = clock();
    _; int N, M; cin >> N >> M;
	vector<ll int> dp(M+1, 0);
	dp[0] = 1;
	for(int i = 0; i < N; i++){
		int x; cin >> x;
		for(int i = x; i <= M; i++){
			dp[i] = (dp[i] + dp[i - x]) % MOD;
		}
	}
    cout << dp[M] << endl;
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

