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
const ull MOD = 998244353;
using namespace std;

void multMat(vector<vector<ull>>& m1, vector<vector<ull>>& m2, int n){
	vector<vector<ull>> resp(n,vector<ull>(n,0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++)
				resp[i][j] = (resp[i][j] + m1[i][k] * m2[k][j] + MOD) % MOD;
		}
	}
	m1 = resp;
}

void Matexp(vector<vector<ull>>& base, ull exp, int n){
	vector<vector<ull>> resp(n,vector<ull>(n,0));
	for(int i = 0; i < n; i++)
		resp[i][i] = 1;
	while(exp > 0){
		if(exp % 2)
			multMat(resp, base, n);
		multMat(base,base, n);
		exp /= 2;
	}
	base = resp;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _; ull n, k; cin >> n >> k;
	vector<vector<ull>> m(n,vector<ull>(n,0));
	for(vector<ull>& i : m) for(ull& j : i) cin >> j;

	Matexp(m,k,n);

	for(vector<ull>& i : m){
		for(ull& j : i) cout << j % MOD << " ";
		cout << endl;
	}
    
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

