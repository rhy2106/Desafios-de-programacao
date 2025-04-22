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
    _; int n; cin >> n;
	vector<vector<int>> dp(n+1,vector<int>(360,0));
	dp[0][0] = 1;
	for(int i = 1; i < n+1; i++){
		int x; cin >> x;
		for(int j = 0; j < 360; j++){
			if(!dp[i-1][j]) continue;
			dp[i][abs((j-x)%360)] = 1;
			dp[i][(j+x)%360] = 1;
		}
	}
    if(dp[n][0]) cout << "YES" << endl;
	else cout << "NO" << endl;
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

