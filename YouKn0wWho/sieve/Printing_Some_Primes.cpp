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
	vector<int> primos(1e8,1);
	primos[0] = primos[1] = 0;
	int cont = 1;
	cout << 2 << endl;
	for(ll i = 3; i < 1e8; i+=2){
		if(primos[i]){
			if(cont % 100 == 0) cout << i << endl;
			cont++;
			for(ll j = i*i; j < 1e8; j+=2*i)
				primos[j] = 0;
		}
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

