#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
int dist[16][16]; // para Floyd-Warshall
int deg[16];      // grau de cada vértice
vector<vector<int>> g(16);

int bfs(int n){
	vector<int> visitados(16,0);
	queue<int> fila;
	fila.push(1);
	while(!fila.empty()){
		int u = fila.front();
		fila.pop();
		if(visitados[u]) continue;
		visitados[u] = 1;
		for(int v : g[u])
			if(!visitados[v]) fila.push(v);
	}
	for(int i = 1; i <= n; i++)
		if(!visitados[i]){
			if(g[i].size() > 0) return 1;
		}
	return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    // inicializa distâncias
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dist[i][j] = (i==j ? 0 : INF);

    int sumEdges = 0;
    for(int i=0;i<m;i++){
        int x, y, w;
        cin >> x >> y >> w;
        sumEdges += w;
        dist[x][y] = min(dist[x][y], w);
        dist[y][x] = min(dist[y][x], w);
		g[x].push_back(y);
		g[y].push_back(x);
        deg[x]++; deg[y]++;
    }

    // Floyd-Warshall para menores caminhos entre todos os pares
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    // verifica conectividade: se houver aresta impossível, retorna -1
	if(bfs(n)){
		cout << -1 << '\n';
		return 0;
    }

    // lista de vértices de grau ímpar
    vector<int> odd;
    for(int i=1;i<=n;i++)
        if(deg[i]%2==1)
            odd.push_back(i);

    int k = odd.size();
    int dp[1<<15];
    for(int mask=0; mask<(1<<k); mask++) dp[mask] = INF;
    dp[0] = 0;

    // DP de pareamento mínimo
    for(int mask=0; mask<(1<<k); mask++){
        if(dp[mask]==INF) continue;
        int i;
        for(i=0;i<k;i++) if(!(mask & (1<<i))) break;
        for(int j=i+1;j<k;j++){
            if(!(mask & (1<<j))){
                int newMask = mask | (1<<i) | (1<<j);
                dp[newMask] = min(dp[newMask], dp[mask]+dist[odd[i]][odd[j]]);
            }
        }
    }

    cout << sumEdges + dp[(1<<k)-1] << '\n';
    return 0;
}

