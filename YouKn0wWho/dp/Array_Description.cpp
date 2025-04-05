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

using namespace std;

int main(){
    // clock_t tinicio, tfim;
    // tinicio = clock();
    _; int N, W; cin >> N >> W;
    vector<int> x(N);
    vector<vector<int>> dp;
    dp.assign(N,vector<int>(W+1,0));
    for(int i = 0; i < N; i++) cin >> x[i];
    int inicio = 0, erro = 1;
    for(int i = 0; i < x.size(); i++){
        if(x[i] != 0){
            erro = 0;
            inicio = i;
            dp[inicio][x[inicio]] = 1;
            break;
        }
    }
    if(erro){
        inicio = 0;
        for(int i = 1; i < W+1; i++) dp[0][i] = 1;
    }
    for (int i = inicio + 1; i < N; i++) {
        // cerr << i << " ";
        for (int v = 1; v <= W; v++) {
            if(x[i] != 0) v = x[i];
            dp[i][v] = dp[i - 1][v]; // Mesmo valor que antes
            if(v > 1) dp[i][v] = (dp[i][v] + dp[i - 1][v - 1]) % 1000000007; // v - 1
            if(v < W) dp[i][v] = (dp[i][v] + dp[i - 1][v + 1]) % 1000000007; // v + 1
            // cerr << dp[i][v] << ',';
            if(x[i] != 0) break;
        }
        // cerr << endl;
    }
    for (int i = inicio - 1; i >= 0; i--) {
        // cerr << i << " ";
        for (int v = 1; v <= W; v++) {
            if(x[i] != 0) v = x[i];
            dp[i][v] = dp[i + 1][v]; // Mesmo valor que antes
            if(v > 1) dp[i][v] = (dp[i][v] + dp[i + 1][v - 1]) % 1000000007; // v - 1
            if(v < W) dp[i][v] = (dp[i][v] + dp[i + 1][v + 1]) % 1000000007; // v + 1
            // cerr << dp[i][v] << ',';
            if(x[i] != 0) break;
        }
        // cerr << endl;
    }

    ll int a = 0, b = 0;
    if(!erro) for(int i : dp[0]) a = (a + i) % 1000000007;
    else a = 1;
    for(int i : dp[N-1]) b = (b + i) % 1000000007;
    ll total = (a * b) % 1000000007;
    cout << total << endl;
    // tfim = clock();
    // cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
