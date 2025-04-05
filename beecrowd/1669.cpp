#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set<int>
#define umap unordered_map<int,vector<int>>
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 2e5+5;
const int LOG = 30;
 
using namespace std;
// mechi no codigo agora ta tudo errado
vector<vector<int>> grafo;
vector<int> visitados;
vector<int> dependencias;
vector<int> id, floresta;
vector<int> depth;
int n1, n2;

int find(int x){
    return id[x] = id[x] == x ? x : find(id[x]);
}

void unir(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(floresta[x] > floresta[y]) swap(x,y);
    dependencias[y] = max(dependencias[y], dependencias[x]);
    floresta[y] += floresta[x];
    id[x] = y;
}


int dfs(int x, int cont){
    int tmp;
    visitados[find(x)] = 1;
    for(int item : grafo[find(x)]){
        if(!visitados[find(item)]) tmp = dfs(find(item),cont+1);
        cont = max(tmp, cont);
    }
    return cont;
}

int main() {
    clock_t tinicio, tfim;
    tinicio = clock();
    _; int d;
    while (cin >> n1 >> n2 >> d, n1 != 0 || n2 != 0 || d != 0) {
        int total = n1 + n2;
        grafo.assign(total, vector<int>());
        dependencias.assign(total, 0);
        visitados.assign(total, 0);
        floresta.assign(total, 1);
        id.assign(total,0);
        iota(id.begin(),id.end(),0);
        for (int i = 0; i < d; ++i) {
            int x, y; cin >> x >> y;
            if((x-1 < n1 && y-1 < n1)||(x-1 >= n1 && y-1 >= n1)) unir(x-1,y-1);
            else grafo[find(y-1)].pb(find(x-1));
            dependencias[find(x-1)]++;
        }
        int trocas = 0;
        for(int i = 0; i < n1 + n2; i++){
            if(dependencias[find(i)] == 0) trocas = max(trocas,dfs(find(i),0));
        }
        cout << trocas+2 << endl;
    }
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
