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
	string a, b; cin >> a >> b;
	for(char& i : a) if( i < 'a' ) i = i + 32;
	for(char& i : b) if( i < 'a' ) i = i + 32;
	for(int i = 0; i < a.size(); i++){
		if(a[i] == b[i] && i == a.size()-1){
			cout << 0 << endl;
		}
		if(a[i] > b[i]){
			cout << 1 << endl;
			break;
		}
		if(a[i] < b[i]){
			cout << -1 << endl;
			break;
		}
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

