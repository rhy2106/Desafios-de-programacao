#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
ll dp[20][11][2][2]; // [pos][last(0..9,10=none)][tight][started]

ll solveDP(int pos, int last, bool tight, bool started) {
    if (pos == (int)s.size()) return 1; // CORREÇÃO: conta também o "0"
    ll &res = dp[pos][last][tight][started];
    if (res != -1) return res;
    res = 0;

    int limit = tight ? (s[pos] - '0') : 9;
    for (int dig = 0; dig <= limit; dig++) {
        if (started && dig == last) continue; // não pode repetir adjacente
        bool ntight = tight && (dig == limit);
        bool nstarted = started || (dig != 0);
        res += solveDP(pos + 1, nstarted ? dig : 10, ntight, nstarted);
    }
    return res;
}

ll countValid(ll x) {
    if (x < 0) return 0;
    s = to_string(x);
    memset(dp, -1, sizeof(dp));
    return solveDP(0, 10, true, false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    if (!(cin >> a >> b)) return 0;
    cout << countValid(b) - countValid(a - 1) << "\n";
    return 0;
}

