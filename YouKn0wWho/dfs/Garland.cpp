#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define pb push_back
#define iPair pair<int,int>
#define uset unordered_set<int>
using namespace std;

vector<vector<int>> grafo;
vector<bool> visitados;
vector<int> temp;
vector<int> id;
int pedaco = 0, inicio;

int dfs(int rotulo){
	int cont = temp[rotulo], cont2 = 0;
	visitados[rotulo] = true;
	for(int item : grafo[rotulo]){
		if(!visitados[item]) cont2 = dfs(item);
		cont += cont2;
		cont2 = 0;
	}
	if(cont == pedaco){
		cont = 0;
		if(rotulo != inicio) id.pb(rotulo);
	}
	return cont;
}

int main(){
	_; int N; cin >> N;
	grafo.assign(N,vector<int>());
	visitados.assign(N,false);
	temp.assign(N,0);
	id.clear();
	int total = 0;
	for(int i = 0; i < N; i++){
		int x, t; cin >> x >> t;
		total += t;
		temp[i] = t;
		if(x == 0){
			inicio = i;
			continue;
		}
		grafo[x-1].pb(i);
	}
	if(total % 3 != 0){
		cout << -1 << endl;
		return 0;
	} else pedaco = total/3;
	dfs(inicio);
	if(id.size() < 2) cout << -1 << endl;
	else cout << id[0]+1 << " " << id[1]+1 << endl;
	return 0;
}
