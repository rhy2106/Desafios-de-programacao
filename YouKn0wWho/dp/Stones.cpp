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

using namespace std;

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _; 
	int N, K; cin >> N >> K;
	vector<int> mov(N,0);
	for(int& i : mov) cin >> i;
	vector<int> dp(K+1,0);
	for(int i = 1; i <= K; i++)
		for(int j : mov)
			if(i - j >= 0 && dp[i-j] == 0)
				dp[i] = 1;
	if(dp[K]) cout << "First" << endl;
	else cout << "Second" << endl;
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

