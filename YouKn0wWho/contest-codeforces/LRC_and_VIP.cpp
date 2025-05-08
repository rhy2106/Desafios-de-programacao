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
		int n; cin >> n;
		vector<int> a(n,0);
		for(int& i : a) cin >> i;
		vector<int> suba(n,0);
		int g = 0, b = 0;
		bool iguais = true;
		for(int i = 0; i < n; i++){
			if(a[i] != a[0]) iguais = false;
			if(g == 0){
				if(a[i] == 1) suba[i] = 2;
				else{
					b++;
					suba[i] = 1;
					g = a[i];
				}
			}else{
				if(__gcd(g,a[i]) != 1){
					g = __gcd(g,a[i]);
					suba[i] = 1;
					b++;
				}
				else suba[i] = 2;
			}
		}
		if(iguais){
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl; 
		if(g == 0 || b == n){
			int cont = 1;
			for(int i = 0; i < n; i++){
				if(a[i] != g && cont > 0){
					cout << 2 << " ";
					cont--;
				} else cout << 1 << " ";
			}
		}else for(int i : suba) cout << i << " ";
		cout << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

