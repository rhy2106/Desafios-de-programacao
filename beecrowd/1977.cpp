#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define f first
#define s second
#define iPair pair<int,int>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

vector<int> floresta,id;

int find(int x){
	return (id[x] = (id[x] == x ? x : find(id[x])));
}

void unir(int x, int y){
	x = find(x); y = find(y);
	if(x == y) return;
	if(floresta[x] > floresta[y]) swap(x,y);
	id[x] = y;
	floresta[y] += floresta[x];
}

int main(){
    _;
    int N;
	cin >> N;
	floresta.assign(N,1);
	id = vector<int> (N);
    iota(id.begin(),id.end(),0);
	vector<tuple<int,int,int>> arestas;
	for(int i = 0; i < N; i++){
		int U, V, W;
		cin >> U >> V >> W;
		arestas.emplace_back(W,U,V);
	}
	int pMin = 0, pMax = 0;
	sort(arestas.begin(),arestas.end(),greater<tuple<int,int,int>>());
	for(auto item : arestas){
		if(find(get<1>(item)) != find(get<2>(item))){
			unir(get<1>(item),get<2>(item));
			pMax += get<0>(item);
		}
	}
	floresta.assign(N,1);
	id = vector<int> (N);
    iota(id.begin(),id.end(),0);
	sort(arestas.begin(),arestas.end());
	for(auto item : arestas){
		if(find(get<1>(item)) != find(get<2>(item))){
			unir(get<1>(item),get<2>(item));
			pMin += get<0>(item);
		}
	}
	cout << pMax << endl;
	cout << pMin << endl;
	return 0;
}
