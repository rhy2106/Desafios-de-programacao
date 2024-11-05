#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

vector<int> id,floresta;

int find(int x){
    // return(id[x] = (id[x] == x ? x : find(id[x]))); é a mesma coisa que tudo isso em baixo
    int tmp;
    if(id[x] == x) tmp = x;
    else tmp = find(id[x]);
    id[x] = tmp;
    return id[x];
}

void unir(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return;
    if(floresta[x] > floresta[y]) swap(x,y);
    id[x] = y;
    floresta[y] += floresta[x];
}

int main(){
    _;
    int m,n;
    while(cin >> m >> n, m != 0 || n != 0){
        id = vector<int> (m);
        floresta = vector<int> (m,1);
        iota(id.begin(),id.end(),0);
        vector<tuple<int,int,int>> arestas;
        int economizado = 0;
        for(int i = 0; i < n; i++){
            int x, y, z;
            cin >> x >> y >> z;
            economizado += z;
            arestas.emplace_back(z,x,y);
        }
        sort(arestas.begin(), arestas.end());
        for(auto item : arestas){
            if(find(get<1>(item)) != find(get<2>(item))){
                unir(get<1>(item),get<2>(item));
                economizado -= get<0>(item);
            }
        }
        cout << economizado << endl;
    }
    return 0;
}
/*
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

class Aresta{
    int v1,v2,p;
public:
    Aresta(int x, int y, int z){
        v1 = x;
        v2 = y;
        p = z;
    }
    int obtv1(){
        return v1;
    }
    int obtv2(){
        return v2;
    }
    int obtp(){
        return p;
    }
    bool operator < (const Aresta& aresta2) const{
        return (p < aresta2.p);
    }

};

vector<Aresta> grafo;
vector<vector<int>> floresta;
int economizado = 0;
void kruskal(){
    for(Aresta pacote : grafo){
        vector<int> tmp;
        if(floresta.empty()){
            tmp.push_back(pacote.obtv1());
            tmp.push_back(pacote.obtv2());
            floresta.push_back(tmp);
        }else{
            int n1 = -1, n2 = -1;
            for(int i = 0; i < floresta.size(); i++){
                for(int j = 0; j < floresta[i].size(); j++){
                    if(pacote.obtv1() == floresta[i][j]) n1 = i;
                    if(pacote.obtv2() == floresta[i][j]) n2 = i;
                }
            }
            if(n1 != -1 && n2 != -1 && n1 == n2) economizado += pacote.obtp();
            if(n1 != -1 && n2 == -1) floresta[n1].push_back(pacote.obtv2());
            if(n2 != -1 && n1 == -1) floresta[n2].push_back(pacote.obtv1());
            if(n1 == -1 && n2 == -1){
                tmp.push_back(pacote.obtv1());
                tmp.push_back(pacote.obtv2());
                floresta.push_back(tmp);
            }
            if(n1 != -1 && n2 != -1 && n1 != n2){
                if(floresta[n1].size() > floresta[n2].size()){
                    for(int item : floresta[n2]) floresta[n1].push_back(item);
                    floresta.erase(next(floresta.begin(),n1));
                } else{
                    for(int item : floresta[n1]) floresta[n2].push_back(item);
                    floresta.erase(next(floresta.begin(),n1));
                }
            }
        }
    }
}

int main(){
    _;
    int m,n;
    while(cin >> m >> n, m != 0 || n != 0){
        grafo.clear();
        floresta.clear();
        economizado = 0;
        for(int i = 0; i < n; i++){
            int x, y, z;
            cin >> x >> y >> z;
            Aresta aresta(x,y,z);
            grafo.push_back(aresta);
        }
        sort(grafo.begin(),grafo.end());
        kruskal();
        cout << economizado << endl;
    }
    return 0;
}
*/