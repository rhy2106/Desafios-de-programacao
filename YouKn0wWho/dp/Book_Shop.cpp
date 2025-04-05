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
    clock_t tinicio, tfim;
    tinicio = clock();
    _; int N, W; cin >> N >> W;
    vector<int> preco, pag, dp;
    dp.assign(W+1,0);
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        preco.pb(x);
    }
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        pag.pb(x);
    }
    for(int i = 0; i < N; i++){
        for(int j = W; j >= 0; j--){
            if(j - preco[i] < 0) continue;
            dp[j] = max(dp[j], dp[j-preco[i]] + pag[i]);
        }
    }
    cout << dp[W] << endl;
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
