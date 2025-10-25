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

vector<vector<iPair>> g;
vector<int> dep;
vector<int> sum;

int bfs(int c, int f){
	priority_queue<iPair> fila;
	int maior = 0;
	for(int i = c; i <= f; i++)
		if(dep[i] == 0) fila.push({0,i});
	while(!fila.empty()){
		auto [peso, pacote] = fila.top();
		fila.pop();
		if(sum[pacote] >= peso) continue;
		sum[pacote] = peso;
		maior = max(maior,peso);
		for(auto [v,w] : g[pacote]){
			if(sum[v] < w + peso) fila.push({w+peso,v});
		}
	}
	return maior;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
    _;
	int n1, n2, d;
	while(cin >> n1 >> n2 >> d, n1 != 0 || n2 != 0 || d != 0){
		int total = n1 + n2;
		g.assign(total+1,vector<iPair>());
		dep.assign(total+1,0);
		sum.assign(total+1,-1);
		for(int i = 0; i < d; i++){
			int x, y; cin >> x >> y;
			if(y <= n1 && x <= n1) g[y].pb({x,0});
			else if( y > n1 && x > n1) g[y].pb({x,0});
			else g[y].pb({x,1});
			dep[x]++;
		}

		int m1 = bfs(1,n1);
		int m2 = bfs(n1+1,total);
		int maior = m1;
		if(m2 == maior) maior++;
		else if(m2 > maior) maior = m2;
		cout << maior + 2 << endl;
		
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

