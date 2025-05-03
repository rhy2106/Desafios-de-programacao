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
	vector<int> primos(n+1,1);
	vector<int> div(n+1,0);
	primos[0] = 0;
	primos[1] = 0;
	for(int i = 2; i <= n; i++){
		if(!primos[i]) continue;
		for(int j = 2*i; j <= n; j+=i){
			primos[j] = 0;
			div[j]++;
		}
	}
	int cont = 0;
	for(int i : div) if(i == 2) cont++;
	cout << cont << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

