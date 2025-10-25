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
const ll MOD = 1e8 + 7;

using namespace std;

ll fastexp(ll b, ll e){
	ll r = 1;
	while(e != 0){
		if(e%2) r = (r*b)%MOD;
		b = (b*b)%MOD;
		e /= 2;
	}
	return r;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	for(int z = 1; z <= tt; z++){
		cout << "Case " << z << ": ";
		ll n; cin >> n;
		ll total = 0;
		for(int i = 0; i < n; i++){
			ll x; cin >> x;
			total = (total + x + MOD) % MOD;
		}
		total = (fastexp(2,n-1)*total) % MOD;
		cout << total << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

