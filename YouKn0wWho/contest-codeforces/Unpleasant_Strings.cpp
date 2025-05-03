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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector<int> alfabetos(n,0);
	vector<int> letras(k,0);
	int cont = 0, total = 0;
	for(int i = n-1; i >= 0; i--){
		if(letras[s[i]-'a'] == total){
			letras[s[i]-'a']++;
			cont++;
			if(cont == k){
				total++;
				cont = 0;
			}
		}
		alfabetos[i] = total;
	}
	int tt; cin >> tt;
	while(tt--){
		string sub; cin >> sub;
		int i = 0, j = 0;
		while( i < n && j < sub.size()){
			if(sub[j] == s[i]) j++;
			i++;
		}
		if(j < sub.size()){
			cout << 0 << endl;
			continue;
		}
		
		cout << alfabetos[i]+1  << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

