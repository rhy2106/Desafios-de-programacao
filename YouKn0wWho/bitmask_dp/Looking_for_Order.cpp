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
	iPair c; cin >> c.f >> c.s;
	int n; cin >> n;
	iPair a[n+1];
	ll d[n+1][n+1];
	a[0] = mp(c.f,c.s);
	for(int i = 1; i <= n; i++) cin >> a[i].f >> a[i].s;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++){
			int dx = a[i].f - a[j].f;
			int dy = a[i].s - a[j].s;
			d[i][j] = dx*dx + dy*dy;
		}

	int full = (1<<n);
	vector<int> dp(full,INF);
	vector<pair<ll,iPair>> parent(full,{-1,{-1,-1}});
	dp[0] = 0;
	for(int mask = 0; mask < full; mask++){
		if(dp[mask] == INF) continue;
		int first = 0;
		for(first = 0; first < n; first++) if(!(mask & (1<<first))) break;
		if(first == n) continue;
		{
			int nmask = mask | (1<<first);
			ll cost = dp[mask] + d[0][first+1] + d[first+1][0];
			if(cost < dp[nmask]){
				dp[nmask] = cost;
				parent[nmask] = {mask,{first,-1}};
			}
		}
		for(int j = first+1; j < n; j++){
			if(mask & (1<<j)) continue;
			int nmask = mask | (1<<first) | (1<<j);
			ll cost = dp[mask] + d[0][first+1] + d[first+1][j+1] + d[j+1][0];
			if(cost < dp[nmask]){
				dp[nmask] = cost;
				parent[nmask] = {mask,{first,j}};
			}
		}
	}

	cout << dp[full-1] << endl;
	vector<int> path;
	int mask = full - 1;
	while (mask) {
		auto [pmask, objs] = parent[mask];
		path.push_back(0);
		path.push_back(objs.first+1); // objeto em 1..n
		if (objs.second != -1) path.push_back(objs.second+1);
		mask = pmask;
	}
	cout << "0 ";
	for (int i = path.size()-1; i >= 0; i--) cout << path[i] << " ";
	cout << endl;

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

