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
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
    _;
	int n, w; cin >> n >> w;
	vector<iTuple> a;
	for(int i = 0; i < n; i++){
		int x, y, z; cin >> x >> y >> z;
		a.emplace_back(x,y,z);
	}
	int m = ( 1 << n );
	vector<int> altura(m,0);
	vector<int> dp(m,-INF);
	dp[0] = INF;
	for(int mask = 0; mask < m; mask++){
		for(int i = 0; i < n; i++){
			if(!(mask & ( 1 << i ))) continue;
			int pmask = mask ^ (1 << i);
			dp[mask] = max(dp[mask], min(dp[pmask] - get<1>(a[i]), get<2>(a[i])));
			altura[mask] += get<0>(a[i]);
		}
	}
	int melhor = 0;
	for(int mask = 0; mask < m; mask++){
		if(melhor < dp[mask] && altura[mask] >= w) melhor = dp[mask];
	}
	if(melhor) cout << melhor << endl;
	else cout << "Mark is too tall" << endl;
		
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

