#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<ll int,ll int>
#define iTuple tuple<double,double,double>
#define uset unordered_set<int>
#define umap unordered_map<int,vector<int>>
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>

using namespace std;

const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;
const ll int MOD = 998244353;

ll int contar(ll int a, ll int b){
	int cont = 0;
	while(true){
		if(a%b != 0) break;
		cont++;
		a = a/b;
	}
	return cont;
}

int main() {
    clock_t tinicio, tfim;
    tinicio = clock();

    _; int n, w; cin >> n >> w;
	vector<vector<int>> dp;
	vector<int> dois(n+1,0);
	vector<int> cinco(n+1,0);
	int max5 = 0;
	for(int i = 1; i <= n; i++){
		ll int x; cin >> x;
		dois[i] = contar(x,2), cinco[i] = contar(x,5);
		max5 += cinco[i];
	}
	dp.assign(w+1, vector<int>(max5+1,-INF));
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++){
        for(int j = min(i,w); j >= 1; j--){
			for(int k = max5; k >= cinco[i]; k--){
				dp[j][k] = max(dp[j][k], dp[j-1][k-cinco[i]] + dois[i]);
			}
		}
	}
    int resp = 0;
	for(int i = 1; i <= max5; i++)
		resp = max(resp, min(dp[w][i],i));

    cout << resp << endl;

    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;

}
