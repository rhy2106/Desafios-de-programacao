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
#define iTuple tuple<ll,ll,ll>
#define uset unordered_set
#define umap unordered_map
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9 + 7;

using namespace std;

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	string s;
	while( cin >> s, s != "."){
		ll n = s.size();
		vector<ll> pi(n,0);
		for(ll i = 1; i < n; i++){
			ll j = pi[i-1];
			while(j > 0 && s[i] != s[j])
				j = pi[j-1];
			if(s[i] == s[j]) j++;
			pi[i] = j;
		}
		ll period_size = n - pi[n-1];
		if(n % period_size) period_size = n;
		cout << n/period_size << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

