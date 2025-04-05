#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define iPair pair<int,int>
#define uset unordered_set<int>
#define umap unordered_map<int,uset>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;
 
vector<vector<int>> grafo;
vector<int> visitados;
uset preto;
uset branco;
int erro;
void dfs(int rotulo){
	stack<iPair> fila;
    fila.push(mp(rotulo,0));
    while(!fila.empty()){
        iPair pacote = fila.top();
        fila.pop();
		visitados[pacote.f] = 1;
		if(pacote.s%2 == 0){
			preto.insert(pacote.f);
			for(int item : grafo[pacote.f]) if(preto.count(item)) erro = 1;
		}else{
			branco.insert(pacote.f);
			for(int item : grafo[pacote.f]) if(branco.count(item)) erro = 1;
		}
		for(int item : grafo[pacote.f]){
            if(!visitados[item]){
                fila.push(mp(item,pacote.s+1));
            }
        }
    }
}
 
int main(){
	_; int N, M; cin >> N >> M;
	vector<iPair> arestas;
	grafo.assign(N,vector<int>());
	visitados.assign(N,0);
	erro = 0;
	for(int i = 0; i < M; i++){
		int x, y; cin >> x >> y;
		grafo[x-1].pb(y-1);
        grafo[y-1].pb(x-1);
		arestas.pb(mp(x-1,y-1));
	}
	dfs(0);
	if(erro) cout << "NO" << endl;
	else{
        cout << "YES" << endl;
		for(iPair i : arestas){
			if(preto.count(i.f)) cout << 1;
			else cout << 0;
		}
		cout << endl;
    }
    return 0;
}