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
	vector<int> primos(1e6+1,1);
	vector<int> quant(1e6+1,0);
	primos[0] = primos[1] = 0;
	for(ll i = 2; i <= 1e6; i++){
		if(!primos[i]) continue;
		for(ll j = i*i; j < 1e6; j+=i)
			primos[j] = 0;
	}
	for(int i = 2; i <= 1e6; i++){
		if(primos[i]){
			string num = to_string(i);
			for(int j = num.size()-1; j >= 0; j--){
				if(num[j] == '0'){
					primos[i] = 0;
					break;
				}
				if(j != 0 && !primos[i%(int)pow(10,j)]){
					primos[i] = 0;
					break;
				}
			}
		}
		if(primos[i]) quant[i] = quant[i-1] + 1;
		else quant[i] = quant[i-1];
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

