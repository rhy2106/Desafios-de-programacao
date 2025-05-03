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
	int n; cin >> n;
	if(n == 1){
		cout << 1 << endl;
		cout << 1 << endl;
		return 0;
	}
	if(n == 2){
		cout << 1 << endl;
		cout << "1 1" << endl;
		return 0;
	}
	vector<int> primos(n+2,1);
	int cont = 0;
	primos[0] = primos[1] = 0;
	for(ll i = 2; i <= n+1; i++){
		if(!primos[i]) continue;
		cont++;
		for(ll j = i*i; j <= n+1; j+=i)
			primos[j] = 0;
	}
	cout << 2 << endl;
	for(int i = 2; i <= n+1; i++){
		if(primos[i]){
			if(cont != 1) cout << 2 << " ";
			else cout << 1 << " ";
			cont--;
		}else cout << 1 << " ";
	}
	cout << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

