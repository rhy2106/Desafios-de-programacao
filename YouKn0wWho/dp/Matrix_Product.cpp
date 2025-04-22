#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define unsigned long long
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
const ll MOD = 998244353;
using namespace std;

ll multMat(vector<vector<ll>>& m1, vector<vector<ll>>& m2, int x, int y, int n){
	ll total = 0;
	for(int i = 0; i < n; i++)
		total += ( m1[x][i] * m2[i][y] + MOD) % MOD;
	return total % MOD;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _; int m, n, t;
	cin >> m >> n >> t;
	vector<vector<ll>> m1(m,vector<ll>(n,0));
	vector<vector<ll>> m2(n,vector<ll>(t,0));
	for(vector<ll> &i : m1) for(ll &j : i) cin >> j;
	for(vector<ll> &i : m2) for(ll &j : i) cin >> j;
	
	vector<vector<ll>> m3(m,vector<ll>(t,0));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < t; j++){
			m3[i][j] = multMat(m1,m2,i,j, n);
		}		
	}

    for(vector<ll> &i : m3){
		for(ll &j : i){
			cout << j << " ";
		}
		cout << endl;
	}

    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

