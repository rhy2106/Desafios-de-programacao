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
	while(tt--){
		int n; cin >> n;
		string s; cin >> s;
		int qnt = count(s.begin(),s.end(), 'a') - count(s.begin(), s.end(), 'b');
		umap<int,int> last;
		last[0] = -1;
		int pref = 0;
		int res = n;
		for(int i = 0; i < n; i++){
			pref += (s[i] == 'a' ? 1 : -1);
			last[pref] = i;
			if(last.count(pref - qnt))
				res = min(res, i - last[pref - qnt]);
		}
		if(res == n) cout << -1 << endl;
		else cout << res << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

