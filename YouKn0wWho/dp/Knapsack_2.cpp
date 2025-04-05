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
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _; 
    ll N, W; cin >> N >> W;
	vector<ll> dp(100001,LINF);
	dp[0] = 0;
	for(ll i = 0; i < N; i++){
		ll w, v; cin >> w >> v;
		for(ll j = 100000; j >= v; j--){
			if(dp[j-v] == LINF) continue;
			dp[j] = min(dp[j], dp[j-v] + w);
		}
	}
	ll maior = 0;
	for(int i = 100000; i >= 0; i--){
		if(dp[i] <= W){
			maior = i;
			break;
		}
	}
	cout << maior << endl;

    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

