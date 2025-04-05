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
    set<ll int> moedas;
    dp.assign(W+1,LINF);
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        moedas.insert(x);
        if(x <= W) dp[x] = 1;
    }
    for(int c : moedas){
        for(int i = c; i <= W; i++){
            dp[i] = min(dp[i],dp[i-c]+1);
        }
    }
    if(dp[W] == LINF) cout << -1 << endl;
    else cout << dp[W] << endl;
	return 0;
}
