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
	vector<int> primos(71,0);
	vector<int> p;
	p.pb(2);
	for(int i = 3; i < primos.size(); i+=2){
		if(!primos[i]) p.pb(i);
		for(int j = i; j < primos.size(); j+=2*i)
			primos[j]++;
	}
int n; cin >> n; vector<iPair> a(71);
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		int tmp = x;
		int mask = 0;
		for(int j = 0; j < p.size(); j++){
			while(x % p[j] == 0){
				mask = mask ^ (1<<j);
				x /= p[j];
			}
		}
		a[tmp].f = mask;
		a[tmp].s++;
	}
	vector<ll> b(n,0);
	b[0] = 1;
	for(int i = 1; i < n; i++) b[i] = (b[i-1]*2)%MOD;
	int full = (1<<p.size());
	vector<ll> dp(full,0);
	dp[0] = 1;
	for(iPair u : a){
		if(u.s == 0) continue;
		vector<ll> ndp(full,0);
		for(int mask = 0; mask < full; mask++){
			ndp[mask] = (ndp[mask] + dp[mask]*b[u.s-1]) % MOD;
			int nmask = mask ^ u.f;
			ndp[nmask] = (ndp[nmask] + dp[mask]*b[u.s-1]) % MOD;
			
		}
		dp.swap(ndp);
	}
	
	cout << dp[0]-1 << endl;
	
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

