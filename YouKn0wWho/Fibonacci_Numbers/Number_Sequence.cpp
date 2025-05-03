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
ll MOD = 1e9 + 7;

using namespace std;

void copiar(ll* a, ll* b){
	a[0] = b[0];
	a[1] = b[1];
	a[2] = b[2];
	a[3] = b[3];
}

void mulmat(ll* a, ll* b){
	ll c[4];
	c[0] = ((a[0]*b[0])%MOD + (a[1]*b[2])%MOD)%MOD;
	c[1] = ((a[0]*b[1])%MOD + (a[1]*b[3])%MOD)%MOD;
	c[2] = ((a[2]*b[0])%MOD + (a[3]*b[2])%MOD)%MOD;
	c[3] = ((a[2]*b[1])%MOD + (a[3]*b[3])%MOD)%MOD;
	copiar(a,c);
}

void matexp(ll* base, ll exp){
	ll res[4] = {1,0,0,1};
	while(exp > 0){
		if(exp%2ll) mulmat(res,base);
		mulmat(base,base);
		exp /= 2ll;
	}
	copiar(base,res);
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;int tt; cin >> tt;
    for(int t = 1; t <= tt; t++){
		cout << "Case " << t << ": ";
        ll a,b,n,mm; cin >> a >> b >> n >> mm;
		MOD = (ll)(pow(10,mm));
		if(n == 0){
			cout << a%MOD << endl;
			continue;
		}
		if(n == 1){
			cout << b%MOD << endl;
			continue;
		}
		ll m[4] = {1,1,1,0};
		matexp(m,n-1);
		int res = m[0];
		if(!(a == 0 && b == 1)) res = ((m[0]*b)%MOD + (m[1]*a)%MOD)%MOD;
		cout << res << endl;
    }
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

