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

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
    _; int t; cin >> t;
    vector<vector<ll int>> dp;
    dp.assign(1000005, vector<ll int>(2,0));
    dp[1][0]=1; dp[1][1]=1;
	for(int i=2; i < 1000005; i++){
		dp[i][1] = (2*dp[i-1][1] + dp[i-1][0]) % MOD;
		dp[i][0] = (dp[i-1][1] + 4*dp[i-1][0]) % MOD;
	}
	while(t--){
		int n; cin >> n;
		cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
	}    
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

// não entendi nada:

// dp[i][1] = 2*dp[i-1][1] + dp[i-1][0]
// dp[i][0]=  dp[i-1][1] + 4*(dp[i-1][0])

// dp[i][1] = 2*dp[i-1][1] +dp[i-1][0]

// =>2*ways because we can either extend the 
// current level to one level down or keep another 
// new tile + 1*ways because we can only keep another 
// new tile and cannot extend the current level downwards

// dp[i][0] = dp[i-1][1]+ 4*dp[i-1][0]

// =>1*ways because we can only keep another new set of 
// tiles and cannot extend the current level + 4*ways 
// because we can either keep a new tile, or extend both
// the sides together or extend a single side at one
// time(left or right side, so intotal 4 ways