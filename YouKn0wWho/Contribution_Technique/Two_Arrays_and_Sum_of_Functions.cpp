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
const ll MOD = 998244353;

using namespace std;

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	ll n; cin >> n;
	vector<ll> a;
	vector<ll> b(n,0);
	for(int i = 1; i <= n; i++){
		ll x; cin >> x;
		x = x*i*(n-i+1ll);
		a.pb(x);
	}
	for(int i = 0; i < n; i++) cin >> b[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll total = 0;
	for(int i = 0; i < n; i++){
		ll tmp = a[i] % MOD;
		tmp = (tmp * b[n-1-i]) % MOD;
		total = (total + tmp) % MOD;
	}
	cout << total << endl;

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

