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
    vector<ll int> dp;
    dp.assign(N+1,INF);
    dp[0] = 0;
    for(int i = 1; i <= N; i++){
        string tmp = to_string(i);
        for(char c : tmp){
            if(c == '0') continue;
            dp[i] = min(dp[i], 1 + dp[i - c + 48]);
        }
    }
    cout << dp[N] << endl;
	return 0;
}
