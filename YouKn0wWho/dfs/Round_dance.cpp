#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define iPair pair<int,int>
#define f first
#define s second
#define uset unordered_set<int>
#define umap unordered_map<int,uset>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;
 
using namespace std;
 
vector<set<int>> grafo;
vector<bool> visitados;
int qmin, qmax;

bool dfs(int rotulo){
	stack<int> fila;
	int fechado = true;
	visitados[rotulo] = rotulo;
    fila.push(rotulo);
    while(!fila.empty()){
        int pacote = fila.top();
		fila.pop();
		visitados[pacote] = true;
		if(grafo[pacote].size() < 2) fechado = false;
        for(int item : grafo[pacote]) if(!visitados[item]) fila.push(item);
    }
	return fechado;
}

int main(){
	_; int Z; cin >> Z;
	for(int z = 0; z < Z; z++){
		int N; cin >> N;
		bool aberto = true;
		grafo.assign(N,set<int>());
		visitados.assign(N,false);
		qmin = 0; qmax = 0;
		for(int i = 0; i < N; i++){
			int x; cin >> x;
			grafo[x-1].insert(i);
			grafo[i].insert(x-1);
		}
		for(int i = 0; i < N; i++){
			if(!visitados[i]){
				qmax +=1;
				if(dfs(i)) qmin += 1;
				else if(aberto){
					qmin +=1;
					aberto = false;
				}
			}
		}
		cout << qmin << " " << qmax << endl;
	}
	return 0;
}
