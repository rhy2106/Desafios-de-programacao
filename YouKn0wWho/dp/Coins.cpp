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
const ll int MOD = 1000000007;
using namespace std;

int main() {
    clock_t tinicio, tfim;
    tinicio = clock();
    _; int N; cin >> N;
	vector<double> p;
	vector<vector<double>> dp;
	dp.assign(N+1,vector<double>(N+1,0));
	p.assign(N,0);
	dp[0][0] = 1;
	for(int i = 0; i < N; i++) cin >> p[i];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N+1; j++){
			dp[i+1][j] += dp[i][j] * (1-p[i]);
			dp[i+1][j+1] += dp[i][j] * p[i];
		}
	}
	double total = 0;
	for(int j = N; j >= (N+1)/2; j--) total += dp[N][j];
	cout << fixed << setprecision(10);
    cout << total << endl;
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

