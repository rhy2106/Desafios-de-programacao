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

vector<int> a;
int c = 0;

template <int len = 1>
int meio(int sum){
	if(len <= sum){
		return meio<min(len*2, 90001)>(sum);
	}
	bitset<len> dp;
	dp[0] = 1;
	for(int j = 1; j < a.size(); j++){
		if(j == c) continue;
		dp |= (dp << a[j]);
		if(dp[sum/2]) return j;
	}
	return -1;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
    _;
	int n; cin >> n;
	a.pb(0);
	int sum = 0;
	for(int i = 0; i < n; i++){
		int tmp; cin >> tmp;
		a.pb(tmp);
		sum += tmp;
	}
	int e;
	vector<int> b = a;
	sort(b.begin(),b.end());
	bool sec = true;
	if(b[1] == b.back() && n % 2 == 1) sec = false;
	if(sec && sum % 2 == 0 && meio(sum)){
		cout << "Second" << endl; cout.flush();
		while(cin >> c, c > 0){
			e = meio(sum);
			cout << e << endl; cout.flush();
			int menor = min(a[c],a[e]);
			a[c] -= menor;
			a[e] -= menor;
			sum -= menor*2;
		}
	} else{
		cout << "First" << endl; cout.flush();
		while( true ){
			for(int i = 1; i <= n; i++){
				if(a[i] <= 0) continue;
				cout << i << endl; cout.flush();
				e = i;
				break;
			}
			cin >> c;
			if(c <= 0) break;
			int menor = min(a[c],a[e]);
			a[c] -= menor;
			a[e] -= menor;
		}
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

