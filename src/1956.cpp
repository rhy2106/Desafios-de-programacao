#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define li long int
#define mp make_pair
#define f first
#define s second
#define iPair pair<li,li>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

vector<vector<iPair>> grafo;
vector<iPair> posicoes;
vector<li> raio;
vector<li> visitados;
vector<li> floresta,id;


int main(){
    _;
    int N, C;
	while(cin >> N, N != 0){
		grafo.assign(N,vector<iPair>());
        posicoes.clear();
		posicoes.resize(N);
		raio.clear();
		raio.resize(N);
		for(int i = 0; i < N; i++){
			int x,y,z;
			cin >> x >> y >> z;
			posicoes[i] = mp(x,y);
			raio[i] = z;
		}
		cin >> C;
		for(int i =0 ; i < C; i++){
			int a1, a2;
			cin >> a1 >> a2;
		}
	}
	return 0;
}
