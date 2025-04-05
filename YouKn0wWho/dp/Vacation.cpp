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
    _; int N; cin >> N;
    vector<vector<ll int>> dp;
    dp.assign(N, vector<ll int>(3,0));
    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
    for(int i = 1; i < N; i++){
        int a, b, c; cin >> a >> b >> c;
        dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + a;
        dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + b;
        dp[i][2] = max(dp[i-1][1],dp[i-1][0]) + c;
    }
    ll int maior = max(dp[N-1][0], dp[N-1][1]);
    maior = max(maior, dp[N-1][2]);
    cout << maior << endl;
    
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
