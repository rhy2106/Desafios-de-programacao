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
 
vector<vector<int>> grafo;
vector<int> visitados;
vector<int> caminho;
map<int,int> arestas;
map<iPair,int> id;
queue<int> seq;
umap galho;
 
void dfs(int rotulo){
	stack<int> fila;
	visitados[rotulo] = rotulo;
    fila.push(rotulo);
    while(!fila.empty()){
        int pacote = fila.top();
		fila.pop();
        for(int item : grafo[pacote]){
            if(visitados[item] == INF){
				visitados[item] = pacote;
                fila.push(item);
            }
        }
    }
}

bool erro(){
	for(int i = 1; i < caminho.size(); i++){
		iPair tmp = mp(caminho[i-1],caminho[i]);
		if(tmp.f == tmp.s) continue;
		arestas[id[tmp]]++;
		if(arestas[id[tmp]] > 2) return true;
	}
	return false;
}

int main(){
	_; int N, M; cin >> N;
	grafo.assign(N,vector<int>());
	visitados.assign(N,INF);
	arestas.clear();
	galho.clear();
	id.clear();
	while(!seq.empty()) seq.pop();
	for(int i = 0; i < N-1; i++){
		int x, y; cin >> x >> y;
		grafo[x-1].pb(y-1);
        grafo[y-1].pb(x-1);
		id[mp(x-1,y-1)] = i+1;
		id[mp(y-1,x-1)] = i+1;
	}
	dfs(0);
	int atual = 0;
	while(cin >> M){
		seq.push(M-1);
		int item = M-1;
		while(item != 0){
			galho[M-1].insert(item);
			item = visitados[item];
		}
		galho[M-1].insert(item);
	}
	seq.push(0);
	while(!seq.empty()){
		int proximo = seq.front();
		seq.pop();
		int i = proximo;
		int cont = caminho.size();
		if(atual == 0){
			while(i != atual){
				caminho.pb(i);
				i = visitados[i];
			}
			caminho.pb(i);
			reverse(caminho.begin() + cont,caminho.end());
			atual = proximo;
			continue;
		}
		if(!proximo){
			while(atual != 0){
				caminho.pb(atual);
				atual = visitados[atual];
			}
			caminho.pb(i);
			break;
		}
		i = atual;
		while(i != 0){
			if(galho[proximo].count(i)) break;
			i = visitados[i];
		}
		while(atual != i){
			caminho.pb(atual);
			atual = visitados[atual];
		}
		caminho.pb(atual);
		cont = caminho.size();
		i = proximo;
		while(i != atual){
			caminho.pb(i);
			i = visitados[i];
		}
		caminho.pb(i);
		reverse(caminho.begin() + cont,caminho.end());
		atual = proximo;
	}
	if(erro()) cout << -1 << endl;
	else for(int i = 0; i < caminho.size(); i++){
		if(i != 0 && caminho[i] == caminho[i-1]) continue;
		cout << caminho[i]+1 << " ";
	}
	cout << endl;
	return 0;
}
