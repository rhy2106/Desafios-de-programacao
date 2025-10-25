#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;

// Fast exponentiation modulo MOD
ll fastpow(ll b, ll e){
    ll r = 1;
    while(e){
        if(e&1) r = (r*b)%MOD;
        b = (b*b)%MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    int B = 18; // Porque n <= 2e5 < 2^18
    for(int i=0;i<n;i++) cin >> a[i];

    int MAX = 1 << B;
    vector<ll> freq(MAX,0);

    // Contar frequência dos elementos
    for(int i=0;i<n;i++) freq[a[i]]++;

    // Superset DP: contar quantos elementos têm todos os bits de mask
    for(int i=0;i<B;i++){
        for(int mask=0;mask<MAX;mask++){
            if(mask & (1<<i)) continue;
			freq[mask] = (freq[mask] + freq[mask|(1<<i)])%MOD;
        }
    }

    // Número de subconjuntos não-vazios com AND >= mask
    vector<ll> f(MAX,0);
    for(int mask=0;mask<MAX;mask++){
        if(freq[mask]==0) f[mask] = 0;
        else f[mask] = (fastpow(2,freq[mask]) - 1 + MOD) % MOD;
    }

    // Möbius inversion para AND
    for(int i=0;i<B;i++){
        for(int mask=0;mask<MAX;mask++){
            if((mask & (1<<i)) == 0){
                f[mask] -= f[mask | (1<<i)];
                if(f[mask]<0) f[mask] += MOD;
            }
        }
    }

    // Imprimir resultados para x = 0..n
    for(int x=0;x<=n;x++){
        cout << f[x] << " ";
    }
    cout << "\n";

    return 0;
}

