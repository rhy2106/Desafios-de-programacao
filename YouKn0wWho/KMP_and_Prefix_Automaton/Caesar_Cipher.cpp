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
umap<char,char> id;

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	while(tt--){
		string a; cin >> a;
		for(int i = 0; i < a.size(); i++){
			id[a[i]] = a[(a.size() + i - 1)%a.size()];
		}
		string b,c; cin >> b >> c;
		string s = b + "#" + c;
		int n = s.size();
		vector<int> res;
		for(int i = 0; i < a.size(); i++){
			if(i != 0) for(int j = b.size()+1; j < n; j++) s[j] = id[s[j]];
			vector<int> pi(n,0);
			for(int j = 1; j < n; j++){
				int k = pi[j-1];
				while(k > 0 && s[j] != s[k])
					k = pi[k-1];
				if(s[j] == s[k]) k++;
				pi[j] = k;
			}

			int cont = 0;
			for(int j = 0; j < n; j++){
				if(pi[j] == b.size()) cont++;
				if(cont > 1) break;
			}

			if(cont == 1) res.pb(i);
		}
		if(res.size() == 0) cout << "no solution" << endl;
		else if(res.size() == 1) cout << "unique: " << res[0] << endl;
		else{
			cout << "ambiguous: ";
			for(int i = 0; i < res.size(); i++){
				cout << res[i];
				if(i != res.size()-1) cout << " ";
			}
			cout << endl;
		}
		
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

