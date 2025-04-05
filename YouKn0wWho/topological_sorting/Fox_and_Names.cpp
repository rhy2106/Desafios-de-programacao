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
set<int> root;
int erro = 0;

void bfs(){
    queue<int> fila;
    for(int i : root) fila.push(i);
    while(!fila.empty()){
        int pacote = fila.front();
        fila.pop();
        ordem.pb(pacote);
        dependencias[pacote] = -1;
        for(int item : grafo[pacote]){
            if(dependencias[item] < 0) erro = 1;
            dependencias[item]--;
            if(dependencias[item] == 0) fila.push(item);
        }
    }
}

int main(){
	_; int M; cin >> M;
    grafo.assign(26,vector<int>());
    dependencias.assign(26,0);
    root.clear();
    ordem.clear();
    erro = 0;
    string p1; cin >> p1;
    for(int i = 0; i < 26; i++) root.insert(i);
    for(int i = 0; i < M-1; i++){
        string p2; cin >> p2;
        int fim = min(p1.size(),p2.size());
        for(int j = 0; j < fim; j++){
            if(p1[j] == p2[j]){
                if(j == fim-1 && p1.size() > p2.size()) erro = 1;
                continue;
            }
            grafo[(int)p1[j] - 97].pb((int)p2[j] - 97);
            root.erase((int)p2[j] - 97);
            dependencias[(int)p2[j] - 97]++;
            break;
        }
        p1 = p2;
    }
    bfs();
    if(erro || ordem.size() != 26){
        cout << "Impossible" << endl;
        return 0;
    }
    for(int i : ordem) cout << (char)(i+97);
    cout << endl;
    return 0;
}
