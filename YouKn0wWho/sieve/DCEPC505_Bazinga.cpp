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
	ll MAXP = 10527449;
	vector<int> p(MAXP+1, 0);
	vector<ll> div2;
	for(ll i = 2; i*i <= MAXP; i++){
		if(p[i]) continue;
		for(ll j = i*i; j <= MAXP; j+=i)
			p[j] = i;
	}
	p[1] = 1;
	for(int i = 2; i < MAXP; i++)
		if(p[i] && p[i] != i/p[i] && !p[i/p[i]] && !p[p[i]])
			div2.pb(i);
		
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		cout << div2[n-1] << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

