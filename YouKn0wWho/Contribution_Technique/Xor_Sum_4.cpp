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

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	ll n; cin >> n;
	vector<ll> num(n,0);
	vector<vector<iPair>> bin(n,vector<iPair>(60,mp(0,0)));
	for(int i = 0; i < n; i++){
		ll x; cin >> x;
		num[i] = x;
		if(i != 0) bin[i] = bin[i-1];
		for(int j = 0; j < 60; j++){
			if(x & (1ll << j)) bin[i][j].f++;
			else bin[i][j].s++;
		}
	}
	ll total = 0;
	for(ll i = 0; i+1 < n; i++){
		for(ll j = 0; j < 60; j++){
			if(num[i] & (1ll << j)) total = (total + (bin[n-1][j].s - bin[i][j].s)*((1ll<<j)%MOD)%MOD)%MOD;
			else total = (total + (bin[n-1][j].f - bin[i][j].f)*((1ll<<j)%MOD)%MOD)%MOD;
		}
	}
	cout << total << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

