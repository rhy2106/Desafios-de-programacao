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
	vector<int> primos(1e7+1, 0);
	vector<int> primos2(1e7+1,1);
	vector<int> quant(1e7+1,0);
	for(ll i = 1; i*i <= 1e7; i++){
		for(ll j = 1; j*j*j*j <= 1e7; j++){
			if(i*i + j*j*j*j > 1e7) break;
			primos[i*i + j*j*j*j] = 1;
		}
	}
	primos2[0] = primos2[1] = 0;
	for(ll i = 2; i < 1e7; i++){
		quant[i] = quant[i-1];
		if(!primos2[i]) continue;
		if(primos[i]) quant[i]++;
		for(ll j = i*i; j < 1e7; j+=i){
			primos[j] = 0;
			primos2[j] = 0;
		}
	}

	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		cout << quant[n] << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

