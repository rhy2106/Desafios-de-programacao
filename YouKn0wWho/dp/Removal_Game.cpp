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
    vector<int> lista;
    ll int total = 0;
    dp.assign(N, vector<ll int>(N,0));
    for(int i = 0; i < N; i++){
        cin >> dp[i][i];
        total += dp[i][i];
        lista.pb(dp[i][i]);
    }

    for(int i = N - 2; i >= 0; i--){
        for(int j = i + 1; j < N; j++){
            dp[i][j] = max(lista[i] - dp[i+1][j], lista[j] - dp[i][j-1]);
        }
    }
    total = (total+dp[0][N-1])/2;
    cout << total << endl;

    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
