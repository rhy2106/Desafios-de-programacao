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
    _; int t; cin >> t;
    vector<int> moedas;
    vector<int> dp;
    int total = 0;
    while(t--){
        int x; cin >> x;
        moedas.pb(x);
        total += x;
    }
    dp.assign(total+1,0);
    dp[0] = 1;
    for(int c : moedas){
        for(int i = total; i >= 0; i--){
            if(i - c < 0) break;
            if(dp[i-c]) dp[i] = 1;
        }
    }
    set<int> ordem;
    for(int i = 0; i < dp.size(); i++)
        if(dp[i] == 1 && i != 0) ordem.insert(i);
    cout << ordem.size() << endl;
    for(int i : ordem) cout << i << " ";
    cout << endl;

    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
