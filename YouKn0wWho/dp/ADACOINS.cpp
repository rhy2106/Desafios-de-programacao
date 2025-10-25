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

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
    _;
	int n, m; cin >> n >> m;
	vector<int> dp(1e5+1, 0);
	vector<int> quant(1e5+1,0);
	vector<int> moedas;
	vector<iPair> query;
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		moedas.pb(x);
	}
	int maior = 0;
	while(m--){
		int x, y; cin >> x >> y;
		query.pb(mp(x,y));
		maior = max(maior,y);
	}

	for(int x : moedas)
		for(int i = maior; i >= x; i--)
			if(dp[i-x]) dp[i] = 1;

	for(int i = 1; i <= maior; i++)
		quant[i] = quant[i-1] + dp[i];

	for(iPair q : query)
		cout << quant[q.s] - quant[q.f-1] << endl;

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

