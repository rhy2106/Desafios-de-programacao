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

ll produto(ll a){
	if(a == 0) return 0;
	ll res = 1;
	while(a){
		res *= a%10;
		a /= 10;
	}
	return res;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	ll a, b; cin >> a >> b;
	string s = to_string(b);
	vector<ll> c;
	c.pb(a);
	c.pb(b);
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] == '0') continue;
		string t = s;
		t[i] = (char)(s[i]-1);
		for(int j = i + 1; j < (int)s.size(); j++){
			t[j] = '9';
		}
		ll val = stoll(t);
		if(val >= a) c.pb(val);
	}
	ll m = a;
	ll maior = -1;
	for (auto x : c) {
        if (x >= a && x <= b) {
            ll p = produto(x);
            if (p > maior) {
                maior = p;
                m = x;
            }
        }
    }
	cout << m << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

