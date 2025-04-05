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
uset preto, branco;
int erro;

void dfs(int rotulo){
	stack<iPair> fila;
    fila.push(mp(rotulo,0));
    while(!fila.empty()){
        iPair pacote = fila.top();
        fila.pop();
		if(visitados[pacote.f]) continue;
		visitados[pacote.f] = 1;
		if(pacote.s%2 == 0) preto.insert(pacote.f);
		else branco.insert(pacote.f);
		for(int item : grafo[pacote.f]){
            if(!visitados[item]){
                fila.push(mp(item,pacote.s+1));
            }
        }
    }
}
 
int main(){
	_; int Z; cin >> Z;
	for(int z = 0; z < Z; z++){
		int N, M; cin >> N >> M;
		grafo.assign(N,vector<int>());
		visitados.assign(N,0);
		preto.clear();
		branco.clear();
		erro = 0;
		for(int i = 0; i < M; i++){
			int x, y; cin >> x >> y;
			grafo[x-1].pb(y-1);
			grafo[y-1].pb(x-1);
		}
		dfs(0);
		if(branco.size() < preto.size()){
			cout << branco.size() << endl;
			for(int i : branco) cout << i+1 << " ";
			cout << endl;
		} else{
			cout << preto.size() << endl;
			for(int i : preto) cout << i+1 << " ";
			cout << endl;
		}
	}
    return 0;
}