#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<ll int,ll int>
#define iTuple tuple<double,double,double>
#define uset unordered_set<int>
#define umap unordered_map<int,vector<int>>
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
#define gcd( x, y )  __gcd( x, y ) // menor divisor comum

const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;
const ll int MOD = 998244353;
using namespace std;

vector<ll int> dp;
vector<ll int> talent, weight;
int n, w;

bool doable(int y) {
    for(int i = 0; i <= w; i++) dp[i] = -LINF;
    dp[0] = 0;
    for(int j = 0; j < n; j++) {
        ll value = 1000*talent[j] - y*weight[j];
        int inc = weight[j];
        for(int k = w; k >= 0; k--) {
            int k1 = min(w, k + inc);
            if(dp[k] == -LINF) continue;
            if(dp[k1] < dp[k] + value)
                dp[k1] = dp[k] + value;
        }
    }

    return dp[w] >= 0;
}


int main() {
    clock_t tinicio, tfim;
    tinicio = clock();
	freopen("talent.in", "r", stdin);
	freopen("talent.out", "w", stdout);
    
    _; cin >> n >> w;
    talent.assign(n,0);
    weight.assign(n,0);
    dp.assign(w+1,-LINF);
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> talent[i];

    // Busca binaria
    int lo = 0;
    int hi = (250 * 1e6) + 1;
    while (hi > lo + 1) {
        int mid = (lo + hi) / 2;
        if (doable(mid)) lo = mid;
        else hi = mid;
    }
    printf("%d\n", lo);

    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
