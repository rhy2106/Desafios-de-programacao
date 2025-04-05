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
#define uset unordered_set
#define umap unordered_map
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;
const ll int MOD = 1e9 + 7;

using namespace std;

ll exp(int base, int power){
	if(power == 0) return 1;
	if(power == 1) return (base + MOD) % MOD;
	ll resp = exp(base, power/2);
	resp = (resp * resp + MOD) % MOD;
	if(power%2 == 1) resp = (resp * base + MOD) % MOD;
	return (resp + MOD) % MOD;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	freopen("poetry.in", "r", stdin);
	freopen("poetry.out", "w", stdout);
    _; int n, m, k; cin >> n >> m >> k;
	vector<iPair> palavras(n,mp(0,0));
	unordered_map<char,int> ordem;
	vector<int> dp(k+1,0);
	vector<int> total(k+1,0);
	for(int i = 0; i < n; i++) cin >> palavras[i].f >> palavras[i].s;
	for(int i = 0; i < m; i++){
		char c; cin >> c;
		if(ordem.count(c)) ordem[c]++;
		else ordem[c] = 1;
	}
	dp[0]=1;
	for(int i = 0; i < k; i++){
		for(int j = 0; j < n; j++){
			if(palavras[j].f + i > k) continue;
			if(palavras[j].f + i == k)
				total[palavras[j].s] = (total[palavras[j].s] + dp[i]) % MOD;
			else
				dp[palavras[j].f + i] = (dp[palavras[j].f + i] + dp[i]) % MOD;
		}
	}
	ll int cont = 1;
	for(auto a : ordem){
		int freq = a.s;
		ll soma = 0;
		for(int i = 0; i <= n; i++){
			if(total[i] == 0) continue;
			soma = (soma + exp(total[i],freq) + MOD) % MOD;
		}
		cont = (cont * soma + MOD ) % MOD;
	}

	cout << cont << endl;

    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
