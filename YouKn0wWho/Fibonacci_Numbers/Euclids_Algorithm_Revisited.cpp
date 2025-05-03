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
const ull MOD = 1e9 + 7;
using namespace std;

void igual(ull *a, ull *b){
	a[0] = b[0];
	a[1] = b[1];
	a[2] = b[2];
	a[3] = b[3];
}

void multmat(ull *a, ull *b){
	ull c[4];
	c[0] = (a[0]*b[0]%MOD + a[1]*b[2]%MOD)%MOD;
	c[1] = (a[0]*b[1]%MOD + a[1]*b[3]%MOD)%MOD;
	c[2] = (a[2]*b[0]%MOD + a[3]*b[2]%MOD)%MOD;
	c[3] = (a[2]*b[1]%MOD + a[3]*b[3]%MOD)%MOD;
	igual(a,c);
}

void matexp(ull *base, ull exp){
	ull res[4] = {1,0,0,1};
	while(exp > 0){
		if(exp%2) multmat(res,base);
		multmat(base,base);
		exp /= 2;
	}
	igual(base,res);
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	while(tt--){
		ull n; cin >> n;
		if(n == 0) cout << 0 << endl;
		else if(n == 1) cout << 2 << endl;
		else{
			ull m[4] = {1,1,1,0};
			matexp(m,n+2);
			cout << m[0] << endl;
		}
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

