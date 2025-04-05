#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>

using namespace std;

set<int> visitados;
map<int,int> grafo;

void bfs(int rotulo, int fim){
    queue<int> fila;
    fila.push(rotulo);
    while(!fila.empty()){
        int pacote = fila.front();
        fila.pop();
        if(pacote == fim) return;
        if(pacote > fim/2) continue;
        visitados.insert(pacote);
        int item = pacote*2, item2 = pacote;
        if(fim/10 >= pacote) item2 = pacote*10+1;
        grafo[item] = pacote;
        if(item2 != pacote) grafo[item2] = pacote;
        if(!visitados.count(item)) fila.push(item);
        if(!visitados.count(item2)) fila.push(item2);
    }
}

int main(){
    _; int N, M; cin >> N >> M;
    visitados.clear();
    grafo.clear();
    stack<int> seq;
    bfs(N, M);
    if(grafo.find(M) != grafo.end()){
        while(M != N){
            seq.push(M);
            M = grafo[M];
        }
        cout << "YES" << endl;
        cout << seq.size()+1 << endl;
        cout << N << " ";
        while(!seq.empty()){
            cout << seq.top() << " ";
            seq.pop();
        }
        cout << endl;
    } else cout << "NO" << endl;
    return 0;
}
