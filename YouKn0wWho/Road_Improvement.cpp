#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair>>
#define gcd( x, y )  __gcd( x, y ) 

using namespace std;

vector<vector<int>> grafo;
vector<int> visitados;

vector<vector<int>> dias;
vector<vector<int>> ordem;
map<iPair,int> id;
int total;

void dfs(int rotulo){
    visitados[rotulo] = 1;
    for(int item : grafo[rotulo]){
        if(!visitados[item]){
            for(int i = 0; i < total; i++){
                if(!dias[i][item] && !dias[i][rotulo]){
                    dias[i][item] = 1;
                    dias[i][rotulo] = 1;
                    ordem[i].pb(id[mp(item,rotulo)]);
                    break;
                }
            }
            dfs(item);
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
    visitados.assign(N,0);
    id.clear();
    total = 0;
    for(int i = 0; i < N-1; i++){
        int x, y; cin >> x >> y;
        grafo[x-1].pb(y-1);
        grafo[y-1].pb(x-1);
        id[mp(x-1,y-1)] = i+1;
        id[mp(y-1,x-1)] = i+1;
    }
    for(vector<int> i : grafo) if(total < i.size()) total = i.size();
    dias.assign(total,visitados);
    ordem.assign(total,vector<int>());
    dfs(0);
    cout << total << endl;
    for(int i = 0; i < ordem.size(); i++){
        if(ordem[i].empty()) break;
        cout << ordem[i].size() << " ";
        for(int j : ordem[i]) cout << j << " ";
        cout << endl;
    }    
    time(&fim);
    cerr << fim - inicio << " segundos" << endl;
    return 0;
}