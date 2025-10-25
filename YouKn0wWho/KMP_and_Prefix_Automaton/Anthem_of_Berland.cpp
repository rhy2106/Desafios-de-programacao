#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s, t;
	while( cin >> s >> t){
		int n = (int)s.size();
		int m = (int)t.size();
		
		// prefix function (pi) for t
		vector<int> pi(m);
		for (int i = 1; i < m; ++i) {
			int j = pi[i-1];
			while (j > 0 && t[i] != t[j]) j = pi[j-1];
			if (t[i] == t[j]) ++j;
			pi[i] = j;
		}
		
		// build automaton go[state][ch] for state 0..m and ch 0..25
		vector<vector<int>> go(m+1, vector<int>(26, 0));
		for (int state = 0; state <= m; ++state) {
			for (int c = 0; c < 26; ++c) {
				if (state < m && c == (t[state] - 'a')) {
					go[state][c] = state + 1;
				} else {
					if (state == 0) go[state][c] = 0;
					else go[state][c] = go[pi[state-1]][c];
				}
			}
		}
		
		const int NEG = -1000000000;
		// dp[state] = max occurrences so far finishing at this state (state in [0..m-1])
		vector<int> dp(m, NEG), ndp(m, NEG);
		dp[0] = 0;
		
		for (int i = 0; i < n; ++i) {
			// reset ndp
			for (int k = 0; k < m; ++k) ndp[k] = NEG;
			
			vector<int> letters;
			if (s[i] == '?') {
				letters.resize(26);
				for (int c = 0; c < 26; ++c) letters[c] = c;
			} else {
				letters.push_back(s[i] - 'a');
			}
			
			for (int state = 0; state < m; ++state) {
				if (dp[state] <= NEG/2) continue;
				for (int c : letters) {
					int nj = go[state][c];
					if (nj == m) {
						// matched full t -> count +1 and jump to pi[m-1]
						int to = pi[m-1];
						ndp[to] = max(ndp[to], dp[state] + 1);
					} else {
						ndp[nj] = max(ndp[nj], dp[state]);
					}
				}
			}
			// swap dp
			dp.swap(ndp);
		}
		
		int ans = 0;
		for (int val : dp) if (val > ans) ans = val;
		cout << ans << '\n';
	}
    return 0;
}

