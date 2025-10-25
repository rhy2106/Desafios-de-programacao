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

vector<ll> id, floresta;

ll find(ll x){
	return id[x] = (id[x] == x ? x : find(id[x]));
}

void unir(ll x, ll y){
	x = find(x); y = find(y);
	if(x == y) return;
	if(floresta[x] < floresta[y]) swap(x,y);
	floresta[x] += floresta[y];
	id[y] = id[x];
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	ll x, y; cin >> x >> y;
	vector<iTuple> arestas;
	floresta.assign(x,1);
	id.assign(x,0);
	iota(id.begin(),id.end(),0);
	ll custo = 0;
	for(ll i = 0; i < y; i++){
		ll a, b, c; cin >> a >> b >> c;
		arestas.emplace_back(c,a-1,b-1);
	}
	sort(arestas.begin(),arestas.end());
	for(auto [c,a,b] : arestas){
		if(find(a) != find(b)){
			unir(a,b);
			custo += c;
		}
	}
	if(floresta[find(0)] != x) cout << "IMPOSSIBLE" << endl;
	else cout << custo << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

