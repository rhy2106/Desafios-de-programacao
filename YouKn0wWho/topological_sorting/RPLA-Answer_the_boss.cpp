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
#define pqueue priority_queue <iPair, vector<iPair>, greater<iPair>>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

vector<vector<int>> grafo;
vector<int> dependencias;
vector<iPair> ordem;
uset root;

void bfs(int N){
    pqueue fila;
    for(int i = 0; i < N; i++) if(root.count(i)) fila.push(mp(1,i));
    while(!fila.empty()){
        iPair pacote = fila.top();
        fila.pop();
        dependencias[pacote.s] = -1;
        ordem.pb(mp(pacote.f,pacote.s));
        for(int item : grafo[pacote.s]){
            dependencias[item]--;
            if(dependencias[item] == 0) fila.push(mp(pacote.f+1,item));
        }
    }
}

int main(){
	_; int Z; cin >> Z;
    for(int z = 0; z < Z; z++){
        cout << "Scenario #" << z + 1 << ":" << endl;
        int N, M; cin >> N >> M;
        grafo.assign(N,vector<int>());
        dependencias.assign(N,0);
        root.clear();
        ordem.clear();
        for(int i = 0; i < N; i++) root.insert(i);
        for(int i = 0; i < M; i++){
            int x, y; cin >> x >> y;
            grafo[y].pb(x);
            root.erase(x);
            dependencias[x]++;
        }
        bfs(N);
        sort(ordem.begin(),ordem.end());
        for(iPair item : ordem) cout << item.f << " " << item.s << endl;
    }
    return 0;
}