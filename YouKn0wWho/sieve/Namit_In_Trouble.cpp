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
	vector<ll> primes(1e5+1, 1);
	primes[0] = primes[1] = 0;
	vector<ll> primos;
	umap<ll,ll> quant;
	ll cont = 0;
	for(ll i = 2; i <= 1e5; i++){
		if(!primes[i]) continue;
		cont++;
		primos.pb(i*i);
		quant[i*i] = cont;
		for(ll j = i*i; j <= 1e5; j+=i)
			primes[j] = 0;
	}
	int tt; cin >> tt;
	while(tt--){
		ll n, m; cin >> n >> m;
		ll low = 0, high = primos.size();
		while(low+1 < high){
			ll mid = (low + high)/2;
			if(primos[mid] > n) high = mid;
			else low = mid;
		}
		ll total = quant[primos[low]];
		if(n < primos[low]) total--;
		low = 0, high = primos.size();
		while(low+1 < high){
			ll mid = (low + high)/2;
			if(primos[mid] > m) high = mid;
			else low = mid;
		}
		ll abaixo = quant[primos[low]];
		if(m < primos[low]) abaixo--;
		cout << total << " " << (total-abaixo >= 0 ? total-abaixo : 0) << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

