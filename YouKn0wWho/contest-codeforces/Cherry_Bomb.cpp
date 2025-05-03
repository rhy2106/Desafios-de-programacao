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
		int n, k; cin >> n >> k;
		vector<int> a(n,0);
		vector<int> b(n,0);
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) cin >> b[i];
		bool pos = true;
		int cont = 0, menor = a[0], maior = a[0], soma = -1;
		for(int i = 0; i < n; i++){
			if(a[i] >= 0) menor = min(menor,a[i]);
			if(b[i] >= 0) menor = min(menor,b[i]);
			maior = max(maior,a[i]);
			maior = max(maior,b[i]);
			if(b[i] == -1){
				cont++;
				continue;
			}
			if(soma == -1) soma = a[i] + b[i];
			if(soma != a[i]+b[i]){
				pos = false;
				break;
			}
		}
		if(soma != -1 && soma < maior) pos = false;
		if(soma > menor + k) pos = false;
		if(!pos){
			cout << 0 << endl;
			continue;
		} else if(cont == n)
			cout << k + menor + 1 - maior << endl;	
		else cout << 1 << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

