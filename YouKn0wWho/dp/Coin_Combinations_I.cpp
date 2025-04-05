#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
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
	_; int N, W; cin >> N >> W;
    vector<ll int> dp;
    vector<ll int> moedas;
    dp.assign(W+1,0);
    for(int i = 0; i < N; i++){
		ll int x; cin >> x;
        moedas.pb(x);
        if(x <= W) dp[x] = 1;
	}
    sort(moedas.begin(),moedas.end());
    for(ll int i = 1; i <= W; i++){
        for(ll int c : moedas){
            if(i - c < 0) break;
            dp[i] = (dp[i] + dp[i-c]) % 1000000007;
        }
    }
	cout << dp[W] << endl;
	return 0;
}
