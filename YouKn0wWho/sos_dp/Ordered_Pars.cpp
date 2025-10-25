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
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	int MAXB = 20;
	int MAXN = (1<<MAXB);
	while(tt--){
		int n; cin >> n;
		vector<int> a(n);
		vector<int> freq(MAXN,0);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			freq[a[i]]++;
		}
		for(int b = 0; b < MAXB; b++){
			for(int mask = 0; mask < MAXN; mask++){
				if(!(mask & (1<<b))) freq[mask|(1<<b)] += freq[mask];
			}
		}
		int ans = 0;
		for(int x : a){
			int mask = ~x & (MAXN-1);
			ans += freq[mask];
		}
		cout << ans << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

