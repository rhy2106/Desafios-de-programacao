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

vector<int> prefix(string s){
	int n = s.size();
	vector<int> pi(n,0);
	for(int i = 1; i < n; i++){
		int j = pi[i-1];
		while(j > 0 && s[i] != s[j])
			j = pi[j-1];
		if( s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

bool ver(string b,string s, int m){
	int n = s.size();
	vector<int> pi(n,0);
	for(int i = 1; i < n; i++){
		int j = pi[i-1];
		while(j > 0 && s[i] != s[j])
			j = pi[j-1];
		if( s[i] == s[j]) j++;
		pi[i] = j;
	}
	for(int i = b.size(); i < n; i++)
		if(pi[i] == b.size()) return true;
	return false;
}
int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	while(tt--){
		string a; cin >> a;
		string secret = "";
		string r = a;
		reverse(r.begin(),r.end());
		int right = 0, left = a.size()+1;
		while(right + 1 != left){
			int m = ( right + left ) / 2;
			string b = a.substr(0,m);
			string s = b + "#" + r;
			if(ver(b,s,m)) right = m;
			else left = m;
		}
		secret = a.substr(0,right);
		reverse(secret.begin(),secret.end());
		cout << secret << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

