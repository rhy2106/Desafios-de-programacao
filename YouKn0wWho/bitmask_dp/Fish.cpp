#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long
#define ld long double
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
    _;
	cout << fixed << setprecision(6);
	int n;
	while(cin >> n){
		ld a[n][n];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> a[i][j];
		int full = (1<<n);
		vector<double> dp(full,0);
		dp[full-1] = 1;
		for(int mask = full-1; mask >= 0; mask--){
			int k = __builtin_popcount(mask);
			if(k == 1) continue;
			int pairs = k*(k-1)/2;
			for(int i = 0; i < n; i++){
				if(!(mask & (1<<i))) continue;
				for(int j = 0; j < n; j++){
					if(i == j) continue;
					if(!(mask & (1<<j))) continue;
					int nmask = mask ^ (1<<j);
					dp[nmask] += (dp[mask] * a[i][j])/pairs;
				}
			}
		}
		for(int i = 0; i < n; i++) cout << dp[(1<<i)] << " ";
		cout << endl;
	}
    return 0;
}

