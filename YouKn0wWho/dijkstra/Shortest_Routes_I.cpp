#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<ll,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set
#define umap unordered_map
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9 + 7;

using namespace std;
vector<ll> dist;
vector<vector<iPair>> g;

void dij(int rotulo){
	priority_queue<iPair> fila;
	fila.push({0,0});
	while(!fila.empty()){
		int pacote = fila.top().s;
		ll p = -fila.top().f;
		fila.pop();
		if(dist[pacote] < p) continue;
		for(auto [w,i] : g[pacote]){
			if(dist[i] > p + w){
				dist[i] = w + p;
				fila.push(mp(-dist[i],i));
			}
		}
	}
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n, m; cin >> n >> m;
	g.assign(n,vector<iPair>());
	dist.assign(n,LINF);
	dist[0] = 0;
	for(int i = 0; i < m; i++){
		ll x, y, w; cin >> x >> y >> w;
		x--; y--;
		g[x].pb(mp(w,y));
	}
	dij(0);
	for(ll i : dist) cout << i << " ";
	cout << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

