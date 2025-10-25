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
	int n, m; cin >> n >> m;
	int num[n], num2[m];
	for(int i = 0; i < n; i++) cin >> num[i];
	for(int i = 0; i < m; i++) cin >> num2[i];
	if(m == 1){
		cout << n << endl;
		return 0;
	}
	vector<int> a;
	for(int i = 1; i < m; i++) a.pb(num2[i-1] - num2[i]);
	a.pb(1e9);
	for(int i = 1; i < n; i++) a.pb(num[i-1] - num[i]);
	vector<int> pi(n+m-1,0);

	for(int i = 1; i < a.size(); i++){
		int j = pi[i-1];
		while(j > 0 && a[j] != a[i])
			j = pi[j-1];
		if(a[j] == a[i]) j++;
		pi[i] = j;
	}
	int cont = 0;
	for(int i = m; i < pi.size(); i++)
		if(pi[i] == m-1) cont++;

	cout << cont << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}


