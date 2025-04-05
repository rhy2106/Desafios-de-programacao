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
	_; int N, K; cin >> N >> K;
    vector<ll int> dp, alturas;
    dp.assign(N,LINF);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
		ll int x; cin >> x;
        alturas.pb(x);
	}
    for(ll int i = 1; i < N; i++){
        for(int j = 1; j <= K; j++){
            if(i - j < 0) break;
            dp[i] = min(dp[i], dp[i-j] + abs(alturas[i] - alturas[i-j]));
        }
    }
	cout << dp[N-1] << endl;
	return 0;
}
