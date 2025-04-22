#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define unsigned long long
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
const ll MOD = 1e8 + 7;
using namespace std;

int main(){
	_; int tt; cin >> tt;
	vector<ll> fib(1e6+1,0);
	uset<ll> isfib;
	fib[1] = 1;
	for(int i = 2; i < 1e6+1; i++){
		fib[i] = fib[i-1] + fib[i-2];
		if(fib[i] > 1e10) break;
		isfib.insert(fib[i]);
	}
	while(tt--){
		ll x; cin >> x;
		if(isfib.count(x)) cout << "IsFibo" << endl;
		else cout << "IsNotFibo" << endl;
    }
    return 0;
}
