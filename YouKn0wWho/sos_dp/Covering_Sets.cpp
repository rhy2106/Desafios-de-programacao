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
	int MAXB = n;
	int MAXN = (1<<MAXB);
	vector<ll> F(MAXN,0),G(MAXN,0),H(MAXN,0);
	for(int i = 0; i < MAXN;i++) cin >> F[i];
	for(int i = 0; i < MAXN;i++) cin >> G[i];
	for(int i = 0; i < MAXN;i++) cin >> H[i];
	
	for(int b = 0; b < MAXB; b++){
		for(int mask = 0; mask < MAXN; mask++){
			int nmask = mask | (1<<b);
			if(!(mask & (1<<b))) F[nmask] = (F[nmask] + F[mask])%MOD;
			if(!(mask & (1<<b))) G[nmask] = (G[nmask] + G[mask])%MOD;
			if(!(mask & (1<<b))) H[nmask] = (H[nmask] + H[mask])%MOD;
		}
	}
	vector<ll> R(MAXN,0);
	for(int i = 0; i < MAXN; i++){ // F * G * H
		R[i] = (F[i] * G[i])%MOD;
		R[i] = (R[i] * H[i])%MOD;
	}
	
	for(int b = 0; b < MAXB; b++){ // mobius
		for(int mask = 0; mask < MAXN; mask++){
			if(!(mask & (1<<b))) R[mask|(1<<b)] = (R[mask|(1<<b)] - R[mask] + MOD) % MOD;
		}
	}

	vector<int> p2(MAXB+1);
	p2[0] = 1;
	ll ans = 0;
	for(int i = 1; i <= MAXB; i++) p2[i] = p2[i-1]*2;
	for(int mask = 0; mask < MAXN; mask++){
		ll qnt = __builtin_popcount(mask);
		ans = (ans + R[mask]*p2[qnt])%MOD;
	}
	cout << ans << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

