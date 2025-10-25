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
	string s; cin >> s;
	int n = s.size();
	vector<int> pi(n,0);
	for(int i = 1; i < n; i++){
		int j = pi[i-1];
		while(j > 0 && s[i] != s[j])
			j = pi[j-1];
		if(s[i] == s[j]) j++;
		pi[i] = j;
	}
	vector<int> cont(n+1,0);
	for(int i = 0; i < n; i++)
		cont[pi[i]]++;
	for(int i = n; i > 0; i--)
		cont[pi[i-1]] += cont[i];
	for(int i = 1; i <= n; i++)
		cont[i]++;
	vector<int> suf;
	suf.pb(n);
	int x = pi[n-1];
	while(x > 0){
		suf.pb(x);
		x = pi[x-1];
	}
	reverse(suf.begin(),suf.end());
	cout << suf.size() << endl;
	for(int i : suf) cout << i << " " << cont[i] << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

