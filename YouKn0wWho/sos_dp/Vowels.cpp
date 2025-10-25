#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set
#define umap unordered_map
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9 + 7;

using namespace std;

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
    _;
    const int MAXB = 24;
    const int MAXN = 1 << MAXB;
    int n; cin >> n;
    vector<int> freq(MAXN, 0);
    for(int i = 0; i < n; i++){
        string x; cin >> x;
        int mask = 0;
        for(int j = 0; j < 3; j++){
            mask |= (1 << (x[j] - 'a'));
        }
        freq[mask]++;
    }

    // f[mask] = número de palavras cujo mask_palavra é subconjunto de mask
    vector<int> f = freq;
    for(int b = 0; b < MAXB; b++){
        for(int mask = 0; mask < MAXN; mask++){
            if(mask & (1 << b)){
                f[mask] += f[mask ^ (1 << b)]; // soma sobre subsets
            }
        }
    }

    const int ALL = MAXN - 1;
    unsigned int res = 0;
    for(int S = 0; S < MAXN; S++){
        int comp = (~S) & ALL;
        int sem_vogal = f[comp];          // palavras sem nenhuma letra de S
        int ans = n - sem_vogal;         // palavras com pelo menos 1 vogal em S
        unsigned int sq = (unsigned int)ans * (unsigned int)ans;
        res ^= sq;
    }

    cout << res << endl;
    tfim = clock();
    cerr << (double)(tfim - tinicio) / CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

