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

int main() {
    clock_t tinicio, tfim;
    tinicio = clock();

    _; int Z; cin >> Z;
    while(Z--){
        ll int N, W; cin >> N >> W;
        vector<pair<ll int, int>> pesos;
        uset id;
        for(int i = 0; i < N; i++){
            ll int x; cin >> x;
            pesos.pb(mp(x,i));
        }
        sort(pesos.begin(), pesos.end(), greater<pair<ll int, int>>());
        ll int total = 0;
		ll int metade = W % 2 == 0 ? W/2 : (W + 1)/2;
        for(pair<ll int, int> item : pesos){
            if(total + item.f <= W){
                total += item.f;
                id.insert(item.s);
                if(total >= metade) break;
            }
        }
        if(total >= metade){
            cout << id.size() << endl;
            for(int i : id) cout << i+1 << " ";
            cout << endl;
        } else cout << -1 << endl;
    }

    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

