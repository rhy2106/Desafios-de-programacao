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

ll lcm(ll a, ll b){
	return a / __gcd(a,b)*b;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	ll n, m;
	while(cin >> n >> m){
		vector<ll> a(m);
		for(int i = 0; i < m; i++) cin >> a[i];
		int div = 0;
		for(int mask = 1; mask < (1<<m); mask++){
			ll num = 1;
			int bits = 0;
			for(int i = 0; i < m; i++){
				if(!(mask & (1<<i))) continue;
				bits++;
				num = lcm(num,a[i]);
				if(num > n) break;
			}
			if(num > n) continue;
			if(bits&1) div += n/num;
			else div -= n/num;
		}
		
		cout << n - div << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

