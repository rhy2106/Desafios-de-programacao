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

vector<int> a;

template <int len=1>
void solve(int sum){
	if(len <= sum){
		solve<min(len*2, 4000001)>(sum);
		return;
	}
	bitset<len> dp;
	dp[0] = 1;
	for(int i : a) dp |= (dp << i);
	int mediana;
	for(int i = (sum+1)/2; i <= sum; i++){
		if(!dp[i]) continue;
		mediana = i;
		break;
	}
	cout << mediana << endl;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n; cin >> n;
	a.assign(n,0);
	int k = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		k += a[i];
	}
	solve(k);
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

