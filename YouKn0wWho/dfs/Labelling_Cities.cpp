#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define iPair pair<int,int>
#define uset unordered_set<int>
#define umap unordered_map<int,vector<int>>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

vector<uset> grafo;
vector<int> visitados;
umap id;
bool erro = false;
int menor = 1;

bool verificar(int item){
	if(menor > visitados[item]) menor = visitados[item];
	const vector<int>& label = id[visitados[item]];
	if(!label.empty()){
		if(grafo[item].size() != grafo[label[0]].size()){
			return false;
		}
		for(int j : grafo[label[0]]){
			if(!grafo[item].count(j)){
				return false;
			}
		}
	}
	id[visitados[item]].pb(item);
	return true;
}

void dfs(int rotulo){
	stack<int> fila;
    fila.push(rotulo);
    while(!fila.empty()){
        int pacote = fila.top();
        fila.pop();
        for(int item : grafo[pacote]){
            bool label = false;
            if(visitados[item] == INF){
                fila.push(item);
				visitados[item] = visitados[pacote];
				if(verificar(item)) continue;
                visitados[item] = visitados[pacote]+1;
                if(verificar(item)) continue;
                visitados[item] = visitados[pacote]-1;
                if(!verificar(item)){
                    visitados[item] = 999999;
                    erro = true;
                }
            }
        }

    }
}

int main(){
	_; int N, M; cin >> N >> M;
	grafo.assign(N,uset());
	visitados.assign(N,INF);
	id.clear();
	erro = false;
	for(int i = 0; i < N; i++) grafo[i].insert(i);
	for(int i = 0; i < M; i++){
		int x, y; cin >> x >> y;
		grafo[x-1].insert(y-1);
        grafo[y-1].insert(x-1);
	}
    visitados[0] = 1;
    id[1].pb(0);
	dfs(0);
	if(erro) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
    	for(int i : visitados) cout << i-menor+1 << " ";
    	cout << endl;
    }
    return 0;
}






