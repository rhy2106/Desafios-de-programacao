#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<double,double,double>
#define uset unordered_set
#define umap unordered_map
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>

using namespace std;

const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;
const ll int MOD = 1e9+7;
const ll int MAXN = 2e6 + 6;

vector<ll> fact(MAXN, 1), invFact(MAXN, 1);

// Exponenciação rápida (Fermat)
ll modPow(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Pré-computa fatoriais e fatoriais inversos
void precomputeFactorials() {
    for (ll i = 2; i < MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    invFact[MAXN-1] = modPow(fact[MAXN-1], MOD-2, MOD);
    for (ll i = MAXN-2; i >= 0; i--) {
        invFact[i] = (invFact[i+1] * (i+1)) % MOD;
    }
}

// Computa C(n, r) % MOD
ll nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return ((fact[n] * invFact[r]) % MOD * invFact[n-r]) % MOD;
}

int main() {
    clock_t tinicio, tfim;
    tinicio = clock();
    
	_;

    precomputeFactorials();

    int n, m, w; cin >> n >> m >> w;
    vector<ll> dp(w+1,0);
    vector<iPair> p(w);
    for(int i = 0; i < w; i++) cin >> p[i].f >> p[i].s;
    p.pb(mp(n, m));
	sort(p.begin(),p.end());

    for(int i = 0; i < p.size(); i++) {
        int x = p[i].f, y = p[i].s;
        dp[i] = nCr(x + y - 2, x - 1);
        for(int j = 0; j < i; j++) {
            int xj = p[j].f, yj = p[j].s;
            if (xj > x || yj > y) continue;
            ll paths = (dp[j] * nCr(x - xj + y - yj, x - xj)) % MOD;
            dp[i] = (dp[i] - paths + MOD) % MOD; 
        }
    }

    cout << dp[w] << endl;
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

