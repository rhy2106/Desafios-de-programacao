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
ll fastexp(ll b, ll e){
	ll res = 1ll;
	while(e != 0ll){
		if(e%2ll) res = (res*b)%MOD;
		b = (b*b)%MOD;
		e /= 2ll;
	}
	return res;
}
int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	ll n; cin >> n;
	vector<ll> a(n,0);
	for(ll& i : a) cin >> i;
	sort(a.begin(),a.end(),greater<ll>());
	ll total = 0;
	for(ll i = 0; i < a.size(); i++){
		total = ( total + ((n - 1ll - 2ll*i)*a[i]) % MOD + MOD) % MOD;
	}
	total = (fastexp(2ll,n-2ll)%MOD * total) % MOD;
	cout << total << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

