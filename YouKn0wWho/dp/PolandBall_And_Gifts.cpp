#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set
#define umap unordered_map
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9 + 7;

using namespace std;

void shift(vector<ull>& dp, ull k){
	int wshift = k / 64;
	int bshift = k % 64;
	vector<ull> dp2 = dp;
	for(int i = dp.size()-1; i >= 0; i--){
		ull v = 0ull;
		int j = i - wshift;
		if(j >= 0) {
			v = dp[j] << bshift;
			if(bshift && j-1 >= 0)
				v |= (dp[j-1] >> (64 - bshift));
		}
		dp2[i] |= v;
	}
	dp.swap(dp2);
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n, m; cin >> n >> m;
	vector<int> a(n+1,0), ciclos;
	vector<int> visitados(n+1,0);
	int maior, menor, dobro = 0, um = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		if(visitados[i]) continue;
		int k = i, cont = 0;
		while(!visitados[k]){
			visitados[k] = 1;
			cont++;
			k = a[k];
		}
		dobro += cont/2;
		um += cont%2;
		ciclos.pb(cont);
	}
	maior = min(m*2,dobro*2);
	if(m > dobro) maior += min(m-dobro,um);
	vector<ull> dp(m/64 + 1,0);
	dp[0] = 1ULL;
	vector<int> freq(n+1,0);
	for(int i : ciclos)
		if(i <= m) freq[i]++;
	for(int i = 2; i <= m; i++){
		int c = freq[i];
		if(!c) continue;
		int take = 1;
		while (c > 0) {
			int t = min(take, c);
			long long peso = 1LL * i * t;
			if (peso <= m) shift(dp, (ull)peso);
			c -= t; 
			take <<= 1;
		}
	}
	if((dp[m/64]) & (1ull << (m%64))) menor = m;
	else menor = min(n,m+1);
	cout << menor << " " << maior << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

