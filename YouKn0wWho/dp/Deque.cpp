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
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _; int N; cin >> N;
	vector<ll> a(N);
	vector<vector<ll>> dp(N,vector<ll>(N,0));
	for(int i = 0; i < N; i++){
		cin >> a[i];
		dp[i][i] = a[i];
	}
	// O(N^2) = pow(10,7)
	for(int i = N-2; i >= 0; i--){
		for(int j = i + 1; j < N; j++){
			dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
		}
	}

	cout << dp[0][N-1] << endl;

    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
