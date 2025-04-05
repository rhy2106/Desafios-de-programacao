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

int dfs(int rotulo){
	stack<iPair> fila;
    fila.push(mp(rotulo,rotulo));
	bool erro = true, erro2 = false;
    while(!fila.empty()){
        iPair pacote = fila.top();
        fila.pop();
		if(visitados[pacote.f]) continue;
		visitados[pacote.f] = 1;
		if(grafo[pacote.f].size() != 2) erro2 = true;
		for(int item : grafo[pacote.f]){
            if(!visitados[item]){
                fila.push(mp(item,pacote.f));
            } else if(item == rotulo && pacote.s != rotulo) erro = false;
        }
    }
	if(!erro && !erro2) return 1;
	return 0;
}
 
int main(){
	_; int N, M; cin >> N >> M;
	grafo.assign(N,vector<int>());
	visitados.assign(N,0);
	int contador = 0;
	for(int i = 0; i < M; i++){
		int x, y; cin >> x >> y;
		grafo[x-1].pb(y-1);
		grafo[y-1].pb(x-1);
	}
	for(int i = 0; i < N; i++){
		if(!visitados[i]) contador += dfs(i);
	}
	cout << contador << endl;
	return 0;
}