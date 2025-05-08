#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ui unsigned int
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
	int tt; cin >> tt;
	for(int t = 1; t <= tt; t++){
		cout << "Case " << t << ":" << endl;
		ll n; cin >> n;
		umap<ll,ll> div;
		ll i = 2, m = n;
		while(i*i <= n){
			while(m%i == 0){
				div[i]++;
				m /= i;
			}
			i++;
		}
		if(m != 1) div[m]++;
		
		vector<ll> ordem;
		ordem.pb(1ll);
		ll index = 1;
		for(auto d : div){
			for(ll i = 1; i <= d.s; i++){
				ll num = pow(d.f,i);
				if(i%2 == 0)
					for(ll j = 0; j < index; j++)
						ordem.pb(ordem[j] * num);
				else
					for(ll j = index-1; j >= 0; j--)
						ordem.pb(ordem[j] * num);
			}
			index = ordem.size();
		}
		for(ll i : ordem) cout << i << " ";
		cout << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

