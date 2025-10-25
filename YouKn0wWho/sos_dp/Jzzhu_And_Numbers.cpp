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
	ll r = 1;
	while(e){
		if(e&1) r = (r*b)%MOD;
		b = (b*b)%MOD;
		e >>= 1;
	}
	return r;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n; cin >> n;
	int MAXB = 20;
	int MAXN = (1<<MAXB);
	vector<ll> freq(MAXN,0);
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		freq[x]++;
	}
	for(int b = 0; b < MAXB; b++){
		for(int mask = 0; mask < MAXN; mask++){
			if(mask & (1<<b)) freq[mask^(1<<b)] = (freq[mask^(1<<b)] + freq[mask])%MOD;
		}
	}
	for(int mask = 0; mask < MAXN; mask++){
		if(freq[mask]) freq[mask] = (fastexp(2,freq[mask])-1 + MOD)%MOD;
	}

	for(int b = 0; b < MAXB; b++){
		for(int mask = 0; mask < MAXN; mask++){
			if(mask & (1<<b)) freq[mask^(1<<b)] = (freq[mask^(1<<b)] - freq[mask] + MOD)%MOD;
		}
	}

	cout << freq[0] << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

