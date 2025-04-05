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
uset preto, branco, vazio;
int erro;

void dfs(int rotulo){
	stack<iPair> fila;
    fila.push(mp(rotulo,0));
    while(!fila.empty()){
        iPair pacote = fila.top();
        fila.pop();
		if(visitados[pacote.f]) continue;
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
	_; int Z; cin >> Z;
	for(int z = 0; z < Z; z++){
		int N, M; cin >> N >> M;
		grafo.assign(N,vector<int>());
		visitados.assign(N,0);
		vazio.clear();
		erro = 0;
		for(int i = 0; i < M; i++){
			int x, y; cin >> x >> y;
			grafo[x-1].pb(y-1);
			grafo[y-1].pb(x-1);
		}
		ll int modulo = 998244353;
		ll int total = 0;
		for(int i = 0; i < N; i++){
			if(!visitados[i]){
				if(grafo[i].empty()){
					vazio.insert(i);
					continue;
				}
				preto.clear();
				branco.clear();
				dfs(i);
				if(erro) break;
				ll int a = 0, b = 0, c = 0;			
				for(int i = 0; i < branco.size(); i++){
					a = a == 0 ? 2 : a * 2;
					if(a > modulo) a = a % modulo;
				}
				for(int i = 0; i < preto.size(); i++){
					b = b == 0 ? 2 : b * 2;
					if(b > modulo) b = b % modulo;
				}
				c = (a + b) % modulo;
				if(c != 0) total = total == 0 ? c : (total*c) % modulo;
			}
		}
		if(erro){
			cout << 0 << endl;
			continue;
		}else{
			for(int i = 0; i < vazio.size(); i++){
				total = total == 0 ? 3 : total * 3;
				total = total % modulo;
			}
			cout << total << endl;
		}
		
	}
    return 0;
}