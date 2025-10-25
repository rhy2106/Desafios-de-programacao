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

vector<int> prefix(const string &s){
	int n = s.size();
	vector<int> pi(n,0);
	for(int i = 1; i < n; i++){
		int j = pi[i-1];
		while(j > 0 && s[i] != s[j])
			j = pi[j-1];
		if(s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	string s;
	while(cin >> s, s != "*"){
		int n = s.size();
		 // dp[l][r] = peso mínimo para s[l..r]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // preencher por comprimento crescente
        for (int len = 1; len <= n; ++len) {
            for (int l = 0; l + len - 1 < n; ++l) {
                int r = l + len - 1;
                // caso base: escrever tudo
                dp[l][r] = len;

                // tentar dividir em duas partes
                for (int k = l; k < r; ++k) {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r]);
                }

                // verificar se s[l..r] é repetição de um bloco menor
                string sub = s.substr(l, len);
                auto pi = prefix(sub);
                int p = len - pi[len-1]; // menor período possível
                if (p < len && len % p == 0) {
                    // se é repetição, posso usar o peso do bloco base
                    dp[l][r] = min(dp[l][r], dp[l][l + p - 1]);
                }
            }
        }

        cout << dp[0][n-1] << "\n";
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

