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

const ll MAXN = 3e5 + 1;

vector<ll> fact(MAXN, 1), invFact(MAXN, 1);

ll modPow(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void precomputeFactorials() {
    for (ll i = 2; i < MAXN; i++)
        fact[i] = (fact[i-1] * i) % MOD;
    invFact[MAXN-1] = modPow(fact[MAXN-1], MOD-2, MOD);
    for (ll i = MAXN-2; i >= 0; i--)
        invFact[i] = (invFact[i+1] * (i+1)) % MOD;
}

ll nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return ((fact[n] * invFact[r]) % MOD * invFact[n-r]) % MOD;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	precomputeFactorials();
	vector<vector<ll>> primos(3e5+1,vector<ll>());
	for(ll i = 2; i <= 3e5; i++){
		if(primos[i].size()) continue;
		for(ll j = i; j <= 3e5; j+=i)
			primos[j].pb(i);
	}
	int tt; cin >> tt;
	while(tt--){
		ll n, m; cin >> n >> m;
		umap<ll,ll> primo;
		for(int i = 0; i < n; i++){
			ll x; cin >> x;
			for(ll j : primos[x])
				primo[j]++;
		}
		ll total = 0;
		ll ctotal = nCr(n,m);
		for(auto p : primo)
			total = (total + p.f*(ctotal-nCr(n-p.s,m)+MOD)%MOD)%MOD;
		cout << total << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

