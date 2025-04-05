#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set<int>
#define umap unordered_map<int,vector<int>>
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
#define gcd( x, y )  __gcd( x, y ) // menor divisor comum

const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;
const ll int MOD = 998244353;
using namespace std;

vector<vector<ll>> dp;
vector<ll> v;
ll n, tt = 1;

ll f(ll ind, ll k){
    if (ind >= n || k==0) return 0;
    ll &x = dp[ind][k];

    if (x != (1)) return x;

    ll ans = 0, sm = 0,  mn = 1e18;

    for (ll i = ind; i <=min(n-1, ind + k); i++){
        mn = min(mn, v[i]);
        sm += v[i];
        ll len = (i - ind + 1);
        ans = min(ans, ((len * mn) - sm) + f(i+1, k - (len - 1)));
    }

    x = ans;

    return x;
}

int main()
{
    clock_t tinicio, tfim;
    tinicio = clock();

    _;cin >> tt;
    while (tt--){
    	ll k, sm = 0;
    	cin >> n >> k;
    	
		v.assign(n,0);
		dp.assign(n+1, vector<ll>(k+1, 1));
   		k = min(k, n);
    	
		for (ll i = 0; i < n; i++){
        	cin >> v[i];
        	sm += v[i];
    	}
    	
		ll ans = sm;
    	ll get_ans = f(0, k);
    	
		ans += get_ans;
    	cout << ans << endl;
	}

    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
