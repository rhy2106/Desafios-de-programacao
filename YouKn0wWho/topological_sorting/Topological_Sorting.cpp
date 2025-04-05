#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set<int>
#define umap unordered_map<int,vector<int>>
#define pqueue priority_queue <int, vector<int>, greater<int>>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

vector<vector<int>> grafo;
vector<int> dependencias;
vector<int> ordem;
uset root;

void bfs(int N){
    pqueue fila;
    for(int i = 0; i < N; i++) if(root.count(i)) fila.push(i);
    while(!fila.empty()){
        int pacote = fila.top();
        fila.pop();
        dependencias[pacote] = -1;
        ordem.pb(pacote);
        for(int item : grafo[pacote]){
            dependencias[item]--;
            if(dependencias[item] == 0) fila.push(item);
        }
    }
}

int main(){
	_; int N, M; cin >> N >> M;
    grafo.assign(N,vector<int>());
    dependencias.assign(N,0);
    root.clear();
    for(int i = 0; i < N; i++) root.insert(i);
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y;
        grafo[x-1].pb(y-1);
        root.erase(y-1);
        dependencias[y-1]++;
    }
    bfs(N);
    if(ordem.size() != N) cout << "Sandro fails." << endl;
    else {
        for(int i : ordem) cout << i+1 << " ";
	    cout << endl;
    }
    return 0;
}