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
	_; int N; cin >> N;
    vector<ll int> dp, alturas;
    dp.assign(N+2,LINF);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
		ll int x; cin >> x;
        alturas.pb(x);
	}
    for(ll int i = 0; i < N-1; i++){
        dp[i+1] = min(dp[i+1], dp[i] + abs(alturas[i] - alturas[i+1]));
        dp[i+2] = dp[i] + abs(alturas[i] - alturas[i+2]);
    }
	cout << dp[N-1] << endl;
	return 0;
}
