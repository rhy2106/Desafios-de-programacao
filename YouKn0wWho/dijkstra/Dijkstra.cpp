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
const ll LINF = 100000000000000;
const ll MOD = 1e9 + 7;

using namespace std;
vector<iPair> dist;
vector<vector<iPair>> g;

void dij(int rotulo){
	priority_queue<iPair> fila;
	fila.push({0,0});
	while(!fila.empty()){
		int pacote = fila.top().s;
		ll p = -fila.top().f;
		fila.pop();
		if(dist[pacote].s < p) continue;
		for(auto [w,i] : g[pacote]){
			if(dist[i].s > p + w){
				dist[i].s = w + p;
				dist[i].f = pacote;
				fila.push(mp(-dist[i].s,i));
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
	dist.assign(n,{-1,LINF});
	dist[0].s = 0;
	for(int i = 0; i < m; i++){
		ll x, y, w; cin >> x >> y >> w;
		x--; y--;
		g[x].pb(mp(w,y));
		g[y].pb(mp(w,x));
	}
	dij(0);
	vector<int>path;
	int x = n-1;
	while(x != -1){
		path.pb(x);
		x = dist[x].f;
	}
	if(path.back() != 0){
		cout << -1 << endl;
		return 0;
	}
	for(int i = path.size()-1; i >= 0; i--) cout << path[i] + 1 << " ";
	cout << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}


