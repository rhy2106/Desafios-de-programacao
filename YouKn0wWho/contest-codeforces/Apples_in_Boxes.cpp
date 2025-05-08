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
		ll n, k; cin >> n >> k;
		vector<ll> a(n,0);
		ll maior, menor, soma = 0, maior_cont = 1;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(i == 0){
				maior = a[i];
				menor = a[i];
			}
			soma  = (soma + a[i])% 2;
			if(i != 0 && maior == a[i]) maior_cont++;
			if(maior < a[i]){
				maior = a[i];
				maior_cont = 1;
			}
			menor = min(menor,a[i]);
		}
		if(maior-menor-1 > k && maior_cont == 1) cout << "Jerry" << endl;
		else if(maior-menor > k && maior_cont > 1) cout << "Jerry" << endl;
		else if(soma%2) cout << "Tom" << endl;
		else cout << "Jerry" << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

