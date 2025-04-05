#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set<int>
#define umap unordered_map<int,vector<int>>
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

vector<int> id, floresta;
vector<vector<iPair>> grafo;
vector<vector<int>> up;
vector<vector<int>> pos;
vector<int> depth;
int logn;
int find(int x){
	return id[x] = (id[x] == x ? x : find(id[x]));
}
void unir(int x, int y){
	x = find(x); y = find(y);
	if(x == y) return;
	if(floresta[x] > floresta[y]) swap(x,y);
	floresta[y] += floresta[x];
	id[x] = y;
}

void dfs(int rotulo, int pai, int k){
	up[rotulo][0] = pai;
	if(pai != -1){
		depth[rotulo] = depth[pai] + 1;
		pos[rotulo][0] = k;
	}
	for(int i = 1; i < logn; i++){
		if(up[rotulo][i-1] == -1) break;
		up[rotulo][i] = up[up[rotulo][i-1]][i-1];
		pos[rotulo][i] = max(pos[rotulo][i-1],pos[up[rotulo][i-1]][i-1]);
	}
	for(iPair item : grafo[rotulo])
		if(item.f != pai) dfs(item.f,rotulo,item.s);
}

int lca(int x, int y){
	int maior = 0;
	if(depth[x] > depth[y]) swap(x,y);
	for(int i = logn-1; i >= 0; i--){
		if(up[y][i] != -1 && depth[up[y][i]] >= depth[x]){
			maior = max(maior, pos[y][i]);
			y = up[y][i];
		}
	}
	if(x == y) return maior;
	for(int i = logn-1; i >= 0; i--){
		if(up[y][i] != -1 && up[y][i] != up[x][i]){
			maior = max(maior, pos[y][i]);
			maior = max(maior, pos[x][i]);
			y = up[y][i];
			x = up[x][i];
		}
	}
	maior = max(maior, pos[y][0]);
	maior = max(maior, pos[x][0]);
	return maior;
}

int main(){
	_; int N, M;
	cin >> N >> M;
	logn = ceil(log2(N));
	grafo.assign(N,vector<iPair>());
	up.assign(N,vector<int>(logn,-1));
	pos.assign(N,vector<int>(logn,0));
	depth.assign(N,0);
	id.assign(N,0);
	floresta.assign(N,1);
	iota(id.begin(),id.end(),0);
	vector<iTuple> arestas, ordem;
	set<iTuple> minimo;
	ll int total = 0;
	for(int i = 0; i < M; i++){
		ll int x, y, k; cin >> x >> y >> k;
		arestas.emplace_back(k,x-1,y-1);
		ordem.emplace_back(k,x-1,y-1);
	}
	sort(arestas.begin(),arestas.end());
	for(iTuple item : arestas){
		if(find(get<1>(item)) == find(get<2>(item))) continue;
		unir(get<1>(item), get<2>(item));
		grafo[get<1>(item)].pb(mp(get<2>(item),get<0>(item)));
		grafo[get<2>(item)].pb(mp(get<1>(item),get<0>(item)));
		minimo.insert(item);
		total += get<0>(item);
	}
	// fim kruskal
	if(M != 0) dfs(0,-1,0); // pre processamento para lca
	for(iTuple item : ordem){ // testes
		if(minimo.count(item)){
			cout << total << endl;
			continue;
		}
		ll int tmp = total + get<0>(item);
		tmp -= lca(get<1>(item), get<2>(item));
		cout << tmp << endl;
	}

	return 0;
}
