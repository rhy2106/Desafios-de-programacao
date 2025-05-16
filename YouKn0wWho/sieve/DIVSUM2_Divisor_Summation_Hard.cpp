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

const ull MAXN = 1e8+1;
ll prime[(ull)MAXN/128 + 1ull];

ull fp(ull base, ull exp){
	ull res = 1;
	while(exp != 0){
		if(exp%2) res = res*base;
		base = base*base;
		exp /= 2;
	}
	return res;
}
int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	vector<ull> primos;
	primos.pb(2);
	for(ull i = 0; i < MAXN/128 + 1; i++) prime[i] = 0;
	for(ll i = 3; i <= MAXN; i+=2){
		if(prime[i/128] & (1ull << ((i%128)>>1))) continue;
		primos.pb(i);
		for(ll j = i*i; j <= MAXN; j+=2*i)
			prime[j/128] |= 1ull << ((j%128)>>1);
	}
	ull tt; cin >> tt;
	while(tt--){
		ull n; cin >> n;
		ull m = n;
		ull soma = 1;
		for(ull p : primos){
			if(p*p >= n) break;
			ull cont = 0;
			if(n%p) continue;
			while(n%p==0){
				cont++;
				n /= p;
			}
			ull pexp = fp(p,cont);
			soma *= (pexp-1)/(p-1) + pexp; 
			// resposta = produtoria( (pow(primo, quant_primo) - 1)/(p-1) )
		}
		if(n != 1) soma *= (n+1);
		cout << soma - m << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
