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
	int n, m; cin >> n >> m;
	multiset<int> s;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		s.insert(x);
	}
	for(int i = 0; i < m; i++){
		int x; cin >> x;
		if(x == 0){
			int y; cin >> y;
			s.insert(y);
		}
		else{
			auto it = s.begin();
			if(x == 1){
				cout << *(s.begin()) << endl;
				s.erase(s.begin());
			}else{
				cout << *prev(s.end()) << endl;
				s.erase(prev(s.end()));
			}
		}
	}
	
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
