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

vector<vector<int>> grafo;
ll total = 0;

template <int len = 1>
void subsum(ll n, vector<ll>& a){
	if(a.empty()) return;
	if(len < n){
		subsum<min(len*2,1000001)>(n, a);
		return;
	}

	sort(a.rbegin(),a.rend());
	a.pb(0);
	if(a[0] >= n/2){
		total += a[0] * (n - a[0]);
		return;
	}
	bitset<len> dp;
	dp[0] = 1;
	int pi = 0;
	for(int i = 1; i < a.size(); i++){
		if(a[i] == a[i-1]) continue;
		int c = i - pi;
		int take = 1;
		while(c > 0){
			int t = min(take,c);
			ll p = 1ll * a[i-1] * t;
			dp |= (dp << p);
			c -= t;
			take <<= 1;
		}
		pi = i;
	}
	ll maior = 0;
	for(int i = 0; i < n; i++){
		if(dp[n/2 - i]){
			maior = n/2-i;
			break;
		} 
	}
	total += maior * (n - maior);
}

int dfs(int rotulo){
	vector<ll> a;
	ll sum = 0;
	for(int i : grafo[rotulo]){
		ll tmp = dfs(i);
		a.pb(tmp);
		sum += tmp;
	}
	if(grafo[rotulo].size() <= 1) return sum + 1;
	
	subsum(sum,a);
	return sum + 1;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n; cin >> n;
	grafo.assign(n,vector<int>());
	for(int i = 1; i < n; i++){
		int x; cin >> x;
		grafo[x-1].pb(i);
	}
	dfs(0);
	cout << total << endl; 
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

