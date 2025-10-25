#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<ll,ll>
#define iTuple tuple<int,int,int>
#define uset unordered_set
#define umap unordered_map
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9 + 7;

using namespace std;
const ll MAXN = 3e5+1;

vector<ll> fact(MAXN, 1);

void precomputeFactorials() {
    for (ll i = 2; i < MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
	precomputeFactorials();
    _;
	ll n; cin >> n;
	vector<iPair> bin(60,mp(0,0));
	for(ll i = 0; i < n; i++){
		ll x; cin >> x;
		for(ll j = 0; j < 60; j++){
			if(x & (1ll << j)) bin[j].f = (bin[j].f + fact[n-1])%MOD;
			else bin[j].s = (bin[j].s + fact[n-1])%MOD;
		}
	}
	ll total = 0;
	for(ll i = 0; i < n; i++){
		ll x; cin >> x;
		for(ll j = 0; j < 60; j++){
			if(x & (1ll << j))
				total = (total + (bin[j].s*((1ll<<j)%MOD))%MOD)%MOD;
			else total = (total + (bin[j].f*((1ll<<j)%MOD))%MOD)%MOD;
		}
	}
	cout << total << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

