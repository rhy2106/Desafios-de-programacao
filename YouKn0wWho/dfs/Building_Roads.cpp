#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>

using namespace std;

vector<int> visitados;
vector<vector<int>> grafo;

void dfs(int rotulo){
    visitados[rotulo] = 1;
    for(int item : grafo[rotulo]){
        if(!visitados[item]) dfs(item);
    }
}

int main(){
    _; int N, M; cin >> N >> M;
    vector<iPair> ruas;
    grafo.assign(N,vector<int>());
    visitados.assign(N,0);
    for(int i = 0; i < M; i++){
        int x1,x2; cin >> x1 >> x2;
        grafo[x1-1].pb(x2-1);
        grafo[x2-1].pb(x1-1);
    }
    for(int i = 0; i < grafo.size(); i++){
        if(!visitados[i]){
            dfs(i);
            if(i) ruas.pb(mp(i-1,i));
        }
    }
    cout << ruas.size() << endl;
    for(iPair item : ruas){
        cout << item.f+1 << " " << item.s+1 << endl;
    }
    return 0;
}
