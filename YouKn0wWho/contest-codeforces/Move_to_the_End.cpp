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
	int tt; cin >> tt;
	while(tt--){
		ll n; cin >> n;
		vector<ll> soma(n+1,0);
		vector<iPair> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i].f;
			a[i].s = i;
			soma[i+1] = a[i].f;
			if(i > 0) soma[i+1] += soma[i];
		}
		sort(a.begin(), a.end(),greater<iPair>());
		for(int i = n; i > 0; i--){
			ll maior = soma[n] - soma[i];

			for(int j = 0; j < n; j++){
				if(a[j].s >= i) continue;
				maior = max(maior, soma[n] - soma[i] + a[j].f);
				break;
			}
			cout << maior << " ";
		}
		cout << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

