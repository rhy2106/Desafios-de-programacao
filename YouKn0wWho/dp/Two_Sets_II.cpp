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
    ll int soma =  N*(N+1)/2;
    cerr << soma << endl;

    vector<ll int> dp;
    vector<bool> vis;
    dp.assign(soma/2+1, 0);
    vis.assign(soma/2+1, false);
    dp[0] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = soma/2; j >= i; j--){
            if(dp[j] + dp[j - i] >= MOD) vis[j] = true;
            dp[j] = (dp[j] + dp[j - i])%(2LL*MOD);
        }
    }
    cout << (soma % 2 == 1 ? 0 : (dp[soma/2]/2LL)%MOD) << endl;
    
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}