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

ll soma(ll d){
	return d*(d+1ll)/2ll;
}

bool ver(ll h, ll d, ll m){
	ll s = m + 1ll;
	ll a = d/s;
	ll r = d%s;
	return h + m-1ll >= soma(a+1ll)*(r) + soma(a)*(s-r);
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	while(tt--){
		ll h, d; cin >> h >> d;
		ll l = -1, r = d;
		while(l+1 != r){
			ll m = (l + r)/2;
			if(ver(h,d,m)) r = m;
			else l = m;
		}
		cout << d + r << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

