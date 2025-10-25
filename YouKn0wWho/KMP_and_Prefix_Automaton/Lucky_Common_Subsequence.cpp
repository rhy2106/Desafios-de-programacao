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
#define umap unordered_map<int,vector<int>>
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
#define gcd( x, y )  __gcd( x, y ) // menor divisor comum
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;
const ll int MOD = 1000000007;

using namespace std;

void kmp( vector<int>& pi, string s){
	int n = s.size();
	for(int i = 1; i < n; i++){
		int j = pi[i-1];
		while( j > 0 && s[i] != s[j] )
			j = pi[j-1];
		if(s[i] == s[j]) j++;
		pi[i] = j;
	}
}

int main() {
    clock_t tinicio, tfim;
    tinicio = clock();
    _; string s, t, virus; cin >> s >> t >> virus;
    int n = s.size(), m = t.size(), v = virus.size();
	int nxt[v+1][26];
	vector<int> pi(v); kmp(pi,virus);
	for(int i = 0; i < v; i++){
		for(char c = 'A'; c <= 'Z'; c++){
			if(i < v && c == virus[i]) nxt[i][c-'A'] = i + 1;
			else if( i > 0 ) nxt[i][c-'A'] = nxt[pi[i-1]][c-'A'];
			else nxt[i][c-'A'] = 0;
		}
	}
	int dp[n+1][m+1][v+1]; memset(dp, -1,sizeof(dp));
	dp[0][0][0] = 0;
	iTuple par[n+1][m+1][v+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
			for(int k = 0; k < v; k++){
				if(dp[i][j][k] == -1) continue;
				if(i < n){
					if( dp[i+1][j][k] < dp[i][j][k]){
						dp[i+1][j][k] = dp[i][j][k];
						par[i+1][j][k] = {i,j,k};
					}
				}
				if(j < m){
					if( dp[i][j+1][k] < dp[i][j][k]){
						dp[i][j+1][k] = dp[i][j][k];
						par[i][j+1][k] = {i,j,k};
					}
				}
				if(i < n && j < m && s[i] == t[j]){
					int nk = nxt[k][s[i]-'A'];
					if(nk < v && dp[i+1][j+1][nk] < dp[i][j][k] + 1){
						dp[i+1][j+1][nk] = dp[i][j][k] + 1;
						par[i+1][j+1][nk] = {i,j,k};
					}
				}
			}
        }
    }
	int best = 0, bk = 0;
	for(int k = 0; k < v; k++){
		if(dp[n][m][k] > best){
			best = dp[n][m][k];
			bk = k;
		}
	}
	if(best == 0){
		cout << 0 << "\n";
		return 0;
	}
	string ans;
	int i = n, j = m, k = bk;
	while (i || j) {
		auto [pi, pj, pk] = par[i][j][k];
		if (pi == i-1 && pj == j-1 && dp[i][j][k] == dp[pi][pj][pk] + 1)
			ans.pb(s[i-1]);
		tie(i,j,k) = make_tuple(pi,pj,pk);
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";

    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
