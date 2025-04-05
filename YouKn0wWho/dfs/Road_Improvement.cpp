#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define mp make_pair
#define pb push_back
#define iPair pair<int,int>
#define uset unordered_set<int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair>>

using namespace std;

vector<vector<int>> grafo;
vector<bool> visitados;
vector<uset> dias;
vector<vector<int>> ordem;
map<iPair,int> mapa;

void dfs(){
	stack<int> fila;
	fila.push(0);
	while(!fila.empty()){
		int pacote = fila.top();
		fila.pop();
		visitados[pacote] = true;
		int j = 0;
		for(int item : grafo[pacote]){
			if(visitados[item]) continue;
			for(int i = j; i < ordem.size(); i++){
				if(dias[pacote].count(i)){
					 if( i == j) j++;
					 continue;
				}
				if(!dias[item].count(i)){
					dias[pacote].insert(i);
					dias[item].insert(i);
					ordem[i].pb(mapa[mp(pacote,item)]);
					break;
				}
			}
			fila.push(item);
		}
	}
}

int main(){
    time_t inicio,fim;
    time(&inicio);
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
	_; int N; cin >> N;
	grafo.assign(N,vector<int>());
	dias.assign(N,uset());
	visitados.assign(N,false);
	int total = 0;
	for(int i = 0; i < N-1; i++){
		int x, y; cin >> x >> y;
		grafo[x-1].pb(y-1);
		grafo[y-1].pb(x-1);
		mapa[mp(x-1,y-1)] = i+1;
		mapa[mp(y-1,x-1)] = i+1;
	}
	for(const vector<int>& i : grafo) if(total < i.size()) total = i.size();
	ordem.assign(total,vector<int>());
	dfs();
	cout << total << endl;
	for(int i = 0; i < total; i++){
		cout << ordem[i].size() << " ";
		for(int j : ordem[i]) cout << j << " ";
		cout << endl;
	}
    time(&fim);
    cerr << fim - inicio << " segundos" << endl;
	return 0;
}
