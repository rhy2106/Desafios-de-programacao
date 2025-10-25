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
	int n; cin >> n;
	int MAXN = (1<<n);
	vector<iPair> dp(MAXN,{0,0});
	for(int i = 0; i < MAXN; i++) cin >> dp[i].f;
	for(int b = 0; b < n; b++){
		for(int mask = 1; mask < MAXN; mask++){
			if(!(mask & (1<<b))) continue;
			vector<int> tmp;
			tmp.pb(dp[mask^(1<<b)].f);
			tmp.pb(dp[mask^(1<<b)].s);
			tmp.pb(dp[mask].f);
			tmp.pb(dp[mask].s);
			sort(tmp.rbegin(),tmp.rend());
			dp[mask].f = tmp[0];
			dp[mask].s = tmp[1];
		}
	}
	int maior = 0;
	for(int mask = 1; mask < MAXN; mask++){
		maior = max(maior, dp[mask].f + dp[mask].s);
		cout << maior << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

