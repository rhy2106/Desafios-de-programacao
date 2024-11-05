#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>

using namespace std;

struct Quadrado{
    int x1,x2,y1,y2;
    Quadrado(int x, int y){
        x1 = x;
        x2 = x;
        y1 = y;
        y2 = y;
    }
};

vector<vector<int>> grafo;
vector<Quadrado> cercado; 
vector<int> visitados;
vector<iPair> posicao;

void dfs(int rotulo){
    visitados[rotulo] = 1;
    if(posicao[rotulo].f < cercado.back().x1) cercado.back().x1 = posicao[rotulo].f;
    if(posicao[rotulo].f > cercado.back().x2) cercado.back().x2 = posicao[rotulo].f;
    if(posicao[rotulo].s < cercado.back().y1) cercado.back().y1 = posicao[rotulo].s;
    if(posicao[rotulo].s > cercado.back().y2) cercado.back().y2 = posicao[rotulo].s;
    for(int item : grafo[rotulo]) if(!visitados[item]) dfs(item);
}

int main(){
    // time_t inicio,fim;
    // time(&inicio);
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);

    _; int N, M; cin >> N >> M;
    grafo.assign(N,vector<int>());
    posicao.assign(N,iPair());
    visitados.assign(N,0);
    cercado.clear();
    for(int i = 0; i < N; i++) cin >> posicao[i].f >> posicao[i].s;
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y;
        grafo[x-1].pb(y-1);
        grafo[y-1].pb(x-1);
    }
    for(int i = 0; i < visitados.size(); i++){
        if(!visitados[i]){
            Quadrado a(posicao[i].f,posicao[i].s);
            cercado.pb(a);
            dfs(i);
        }
    }
    int perimetro = -1;
    for(int i = 0; i < cercado.size(); i++){
        int tamanho = abs(cercado[i].x1 - cercado[i].x2)*2 + abs(cercado[i].y1 - cercado[i].y2)*2;
        if(perimetro < 0) perimetro = tamanho;
        else if(tamanho < perimetro) perimetro = tamanho;
    }
    cout << perimetro << endl;
    // time(&fim);
    // cerr << fim - inicio << " segundos" << endl;
    return 0;
}
