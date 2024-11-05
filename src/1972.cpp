#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define f first
#define s second
#define iPair pair<int,int>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

vector< vector<iPair> > grafo;
vector<char> labirinto;
vector<int> distMin;
vector<int> visitados;

void bfs(int inicio){
    pqueue fila;
    fila.push(mp(0,inicio));
    while(!fila.empty()){
        iPair pacote = fila.top();
        fila.pop();
        if(visitados[pacote.s]) continue;
        if(pacote.f < distMin[pacote.s]) distMin[pacote.s] = pacote.f;
        visitados[pacote.s] = 1;
        for(int i = 0 ; i < grafo[pacote.s].size(); i++){
        	int p = distMin[pacote.s] + grafo[pacote.s][i].s;
			fila.push(mp(p,grafo[pacote.s][i].f));
        }
    }
}

void montar(int i, int soma, int C, int L){
    if(i%C == 0 && soma == -1) return;
	if((i+1)%C == 0 && soma == 1) return;
	if(i-C < 0 && soma == -C) return;
	if(i+C >= C*L && soma == C) return;
	if(labirinto[i+soma] == '#') return;
	else if(labirinto[i+soma] == 'E' || labirinto[i+soma] == 'H' ||
	labirinto[i+soma] == '.') grafo[i].push_back(mp(i+soma,0));
	else grafo[i].push_back(mp(i+soma,(int)labirinto[i+soma]-48));
}

int main(){
    _;
    int L, C, inicio, fim;
    cin >> L >> C;
    cin.ignore();
	labirinto.resize(L*C);
	grafo.assign(L*C,vector<iPair>());
    distMin.assign(L*C,999999999);
    visitados.assign(L*C,0);
	for(int i = 0 ; i < L; i++){
        string tmp;
        getline(cin,tmp);
        for(int j = 0; j < C; j++){
			labirinto[j+(i*C)] = tmp[j];
		}
    }
    for(int i = 0; i < C*L; i++){
		if(labirinto[i] == 'H') inicio = i;
		if(labirinto[i] == 'E') fim = i;
		for(int j : {-1,1,C,-C}) montar(i,j,C,L);
	}
	bfs(inicio);

	if(visitados[fim]) cout << distMin[fim] << endl;
    else cout << "ARTSKJID" << endl;
    return 0;
}
