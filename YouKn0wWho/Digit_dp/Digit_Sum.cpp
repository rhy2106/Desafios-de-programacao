#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007LL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string K;
    int D;
    if(!(cin >> K >> D)) return 0;
    
    int n = (int)K.size();
    vector<int64> tight(D, 0), loose(D, 0);
    tight[0] = 1; // prefixo vazio
    
    for(int i = 0; i < n; ++i){
        int digit = K[i] - '0';
        vector<int64> next_tight(D, 0), next_loose(D, 0);
        
        // transições a partir de estados tight
        for(int r = 0; r < D; ++r){
            if(tight[r] == 0) continue;
            int64 ways = tight[r];
            for(int d = 0; d <= digit; ++d){
                int nr = (r + d) % D;
                if(d == digit){
                    next_tight[nr] += ways;
                    if(next_tight[nr] >= MOD) next_tight[nr] -= MOD;
                } else {
                    next_loose[nr] += ways;
                    if(next_loose[nr] >= MOD) next_loose[nr] -= MOD;
                }
            }
        }
        
        // transições a partir de estados loose (já livres: 0..9)
        for(int r = 0; r < D; ++r){
            if(loose[r] == 0) continue;
            int64 ways = loose[r];
            for(int d = 0; d <= 9; ++d){
                int nr = (r + d) % D;
                next_loose[nr] += ways;
                if(next_loose[nr] >= MOD) next_loose[nr] -= MOD;
            }
        }
        
        tight.swap(next_tight);
        loose.swap(next_loose);
    }
    
    int64 ans = (tight[0] + loose[0]) % MOD;
    // excluir o 0 (pois queremos 1..K). K >= 1 conforme restrição.
    ans = (ans - 1 + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}

