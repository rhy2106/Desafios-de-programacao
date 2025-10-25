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
	int MAXB = 22;
	int MAXN = (1<<MAXB);
	int n; cin >> n;
	vector<int> a(n);
	vector<int> ans(MAXN,-1);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		ans[a[i]] = a[i];
	}
	for(int b = 0; b < MAXB; b++)
		for(int mask = 0; mask < MAXN; mask++)
			if(!(mask & (1<<b)))
				if(ans[mask^(1<<b)] == -1)
					ans[mask^(1<<b)] = ans[mask];
	int M = MAXN-1;
	for(int i : a){
		int m = (~i & M);
		cout << ans[m] << endl;	
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

