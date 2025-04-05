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
	_; ll int N, W; cin >> N >> W;
    vector<ll int> dp;
    dp.assign(W+1,0);
    for(int i = 0; i < N; i++){
		ll int k, x; cin >> k >> x;
        for(int i = W; i >= 0; i--){
            if(i - k < 0) break;
            dp[i] = max(dp[i], dp[i-k] + x);
        }
	}
	cout << dp[W] << endl;
	return 0;
}
