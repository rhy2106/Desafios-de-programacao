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

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);

    _; ll int t, a, b; cin >> t >> a >> b;
    vector<ll int> dp, dp2;
    dp.assign(t+1, 0);
    dp2.assign(t+1, 0);
    dp[0] = 1;
	dp2[0] = 1;
    for(int i : {a,b}){
        for(int j = 0; j <= t; j++){
            if(j - i < 0) continue;
			if(dp[j - i] == 0) continue;
			dp[j] = 1;
			dp2[floor(j/2)] = 1;
        }
    }
	for(int i : {a,b}){
        for(int j = 0; j <= t; j++){
            if(j - i < 0) continue;
			if(dp2[j - i] == 0) continue;
			dp2[j] = 1;
        }
    }
	int maior = 0;
	for(int i = t; i >= 0; i--){
		if(dp[i] != 0 || dp2[i] != 0){
			maior = i;
			break;
		}
	}
    cout << maior << endl;
    
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}