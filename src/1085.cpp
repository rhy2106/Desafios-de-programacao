#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define f first
#define s second
#define iTuple tuple<int,int,int>
#define iicTuple tuple<int,int,char>
#define iPair pair<double,double>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >
#define tqueue priority_queue<iicTuple, vector<iicTuple>, greater<iicTuple> >

using namespace std;

map<string,int> linguas;
vector<vector<iicTuple>> grafo;
vector<int> precoMin;
vector<int> visitados;

void bfs(int rotulo,int fim){
    tqueue fila;
    iicTuple item = {0, rotulo, '.'};
    fila.push(item);
    while(!fila.empty()){
        iicTuple pacote = fila.top();
        fila.pop();
        if(visitados[get<1>(pacote)]) continue;
        precoMin[get<1>(pacote)] = get<0>(pacote);
        visitados[get<1>(pacote)] = 1;
        for(int i = 0; i < grafo[get<1>(pacote)].size(); i++){
            int p = get<0>(pacote) + get<0>(grafo[get<1>(pacote)][i]);
            if(get<1>(grafo[get<1>(pacote)][i]) == fim && get<2>(grafo[get<1>(pacote)][i]) == get<2>(pacote)) visitados[get<1>(pacote)] = 0;
            if(!visitados[get<1>(grafo[get<1>(pacote)][i])] && get<2>(grafo[get<1>(pacote)][i]) != get<2>(pacote))
                fila.push({p,get<1>(grafo[get<1>(pacote)][i]),get<2>(grafo[get<1>(pacote)][i])});
        }
    }
}

int main(){
    _;
    int M;
    while(cin >> M, M != 0){
        string l1, l2;
        grafo.assign((M+1)*2,vector<iicTuple>());
        visitados.assign((M+1)*2,0);
        precoMin.assign((M+1)*2,9999999);
        linguas.clear();
        cin >> l1 >> l2;
        linguas[l1] = linguas.size();
        linguas[l2] = linguas.size();
        for(int i = 0; i < M; i++){
            string l3,l4,palavra;
            cin >> l3 >> l4 >> palavra;
            if(linguas.find(l3) == linguas.end()) linguas[l3] = linguas.size();
            if(linguas.find(l4) == linguas.end()) linguas[l4] = linguas.size();
            grafo[linguas[l3]].emplace_back(palavra.size(),linguas[l4],palavra[0]);
            grafo[linguas[l4]].emplace_back(palavra.size(),linguas[l3],palavra[0]);
        }
        bfs(linguas[l1],linguas[l2]);
        if(precoMin[linguas[l2]] != 9999999) cout << precoMin[linguas[l2]] << endl;
        else cout << "impossivel" << endl;
    }
   return 0;
}