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

const int MAXN = 19;
vector<int> g[MAXN];
ll dp[1<<MAXN][MAXN];
int popc[1<<MAXN];

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n, w; cin >> n >> w;
	for(int i = 0; i < w; i++){
		int x, y; cin >> x >> y;
		x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	int m = ( 1 << n );
	ll total = 0;

	for(int mask = 0; mask < m; mask++)
		popc[mask] = __builtin_popcount(mask);

	for(int cmc = 0; cmc < n; cmc++){
		memset(dp,0,sizeof(dp));
		dp[1<<cmc][cmc] = 1;
		for(int mask = (1<<cmc); mask < m; mask++){
			if(!(mask & (1 << cmc))) continue;
			for(int i = 0; i < n; i++){
				if(!(mask & (1 << i))) continue;
				if(dp[mask][i] == 0) continue;

				for(int v : g[i]){
					if(v < cmc) continue;
					if(mask & (1 << v)){
						if(v == cmc && popc[mask] >= 3)
							total += dp[mask][i];
						continue;
					}
					dp[mask | (1 << v)][v] += dp[mask][i];
				}
			}
		}
	}
	cout << total / 2 << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

