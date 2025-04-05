#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set<int>
#define umap unordered_map<int,vector<int>>
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

vector<vector<int>> par;
vector<iPair> inout;
vector<uset> grafo;
vector<int> depth;
int cont;
int LOG;

void dfs(int rotulo, int pai){
	inout[rotulo].f = cont++;
	par[rotulo][0] = pai;
	if(pai != -1) depth[rotulo] = depth[pai] + 1;
	for(int i = 1; i < LOG; i++)
		if(par[rotulo][i-1] != -1)
			par[rotulo][i] = par[par[rotulo][i-1]][i-1];
	for(int item : grafo[rotulo])
		if(item != pai) dfs(item,rotulo);
	inout[rotulo].s = cont++;
}

bool ispai(int x, int y){
	return inout[x].f <= inout[y].f && inout[x].s >= inout[y].s;
}

int lca(int x, int y){
    if(ispai(x,y)) return x;
    if(ispai(y,x)) return y;
	for(int i = LOG-1; i >= 0; i--)
		if(par[x][i] != -1 && !ispai(par[x][i],y))
			x = par[x][i];
	return par[x][0];
}

int main(){
	_; int N, q; cin >> N >> q;
	cont = 0;
	depth.assign(N,0);
	LOG = ceil(log2(N));
	inout.assign(N,{0,0});
	grafo.assign(N,uset());
	par.assign(N,vector<int>(LOG,-1));
	int root = 0;
	for(int i = 1; i < N; i++){
		int x; cin >> x;
		grafo[x-1].insert(i);
		grafo[i].insert(x-1);
	}
	dfs(0,-1);
	while(q--){
        int x, y, z; cin >> x >> y >> z;
        x--; y--; z--;
        if(depth[x] < depth[y]) swap(x,y);
        if(depth[x] < depth[z]) swap(x,z);
        if(depth[y] < depth[z]) swap(y,z);
        int a1,a2,a3,d,d1,d2,d3;
		a1 = lca(x,y); a2 = lca(x,z); a3 = lca(y,z);
        d = depth[x] + depth[y] - 2*depth[a1];
        if(d < depth[x] + depth[z] - 2*depth[a2]){
            swap(y,z);
            swap(a1,a2);
        }
		if(a1 != z && (ispai(z,x) && ispai(z,y)) || (!ispai(z,x) && !ispai(z,y))){
			if(depth[a1] >= depth[a2] && depth[a1] >= depth[a3]){
				d1 = depth[x] - depth[a1];
				d2 = depth[y] - depth[a1];
				d3 = depth[z] + depth[a1] - 2*depth[lca(z,a1)];
			}
			else if(depth[a2] >= depth[a1] && depth[a2] >= depth[a3]){
				d1 = depth[x] - depth[a2];
				d2 = depth[z] - depth[a2];
				d3 = depth[y] + depth[a2] - 2*depth[lca(y,a2)];
			}
			else if(depth[a3] >= depth[a1] && depth[a3] >= depth[a2]){
				d1 = depth[z] - depth[a3];
				d2 = depth[y] - depth[a3];
				d3 = depth[x] + depth[a3] - 2*depth[lca(x,a3)];
			}
		} else{
			d1 = depth[x] + depth[z] - 2*depth[a2];
			d2 = depth[y] + depth[z] - 2*depth[a3];
			d3 = 0;
		}
		int cont = max({d1,d2,d3});
		cout << cont + 1 << endl;
	}

	return 0;
}
