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

int N,M;
vector<vector<char>> matriz;
vector<vector<bool>> visitados;
vector<int> id,floresta,quadros;

int find(int x){
    return (id[x] = (id[x] == x ? x : find(id[x])));
}

void unir(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(floresta[x] > floresta[y]) swap(x,y);
    floresta[y] += floresta[x];
    quadros[y] += quadros[x];
    id[x] = y;
}

iPair sumpar(iPair a, iPair b){
    a.f += b.f;
    a.s += b.s;
    return a;
}

int invmat(iPair p){
    return p.f*M + p.s;
}

void bfs(iPair rotulo){
    vector<iPair> mov = {{1,0},{-1,0},{0,1},{0,-1}};
    queue<iPair> fila;
    fila.push(rotulo);
    while(!fila.empty()){
		queue<iPair> vist;
        iPair pacote = fila.front();
        fila.pop();
        if(matriz[pacote.f][pacote.s] == '*') continue;
        if(visitados[pacote.f][pacote.s]) continue;
        visitados[pacote.f][pacote.s] = true;
        for(iPair m : mov){
            iPair tmp = sumpar(pacote,m);
			if(tmp.f < 0 || tmp.s < 0) continue;
			if(tmp.f >= N || tmp.s >= M) continue;
			if(matriz[tmp.f][tmp.s] == '*'){
				quadros[invmat(pacote)]++;
				continue;
            }
			if(visitados[tmp.f][tmp.s]) vist.push(tmp);
			else fila.push(tmp);
        }
		while(!vist.empty()){
			 unir(invmat(pacote),invmat(vist.front()));
			vist.pop();
		}
	}
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
    int K; cin >> N >> M >> K;
    floresta.assign(N*M,1);
    id.assign(N*M,0);
    iota(id.begin(),id.end(),0);
    quadros.assign(N*M,0);
    visitados.assign(N,vector<bool>(M,false));
    matriz.assign(N,vector<char>(M,'.'));
    for(int i = 0; i < N; i++){
        string tmp; cin >> tmp;
        for(int j = 0; j < M; j++){
            matriz[i][j] = tmp[j];
			if(tmp[j] == '*') id[invmat(mp(i,j))] = 0;
        }
    } 
    for(int i = 1; i < N-1; i++)
		for(int j = 1; j < M-1; j++)
	        if(matriz[i][j] != '*' && !visitados[i][j]){
				bfs(mp(i,j));

			}

    while(K--){
        int x, y; cin >> x >> y;
        cout << quadros[id[invmat(mp(x-1,y-1))]] << endl;
    }
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

