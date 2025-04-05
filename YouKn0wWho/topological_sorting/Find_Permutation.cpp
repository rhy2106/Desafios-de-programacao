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
#define umap unordered_map<int,int>
#define pqueue priority_queue <int, vector<int>, greater<int>>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

vector<vector<int>> grafo;
vector<int> dependencias; 
vector<int> ordem;
int erro = 0;

void bfs(int N){
    int cont = 0;
    queue<int> fila;
    for(int i = 0; i < N; i++) if(dependencias[i] == 0) fila.push(i);
    while(!fila.empty()){
        if(fila.size() != 1) erro = 1;
        int pacote = fila.front();
        fila.pop();
        ordem[pacote] = cont++;
        dependencias[pacote] = -1;
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
    ordem.assign(N,0);
    erro = 0;
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y;
        grafo[x-1].pb(y-1);
        dependencias[y-1]++;
    }
    bfs(N);
    if(erro){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for(int i : ordem) cout << i+1 << " ";
    cout << endl;
    return 0;
}