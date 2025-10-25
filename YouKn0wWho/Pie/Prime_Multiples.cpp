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
    _;
	ll n, k; cin >> n >> k;
	ll a[k];
	for(int i = 0; i < k; i++) cin >> a[i];
	ll total = 0;
	for(int mask = 1; mask < (1<<k); mask++){
		ll num = 1;
		int b = 0;
		for(int i = 0; i < k; i++){
			if(!(mask & (1<<i))) continue;
			b++;
			num = (num > n / a[i]) ? n+1 : num*a[i];
			if(num > n) break;
		}
		if(num > n) continue;
		if(b&1) total += n/num;
		else total -= n/num;
	}
	cout << total << endl;
    return 0;
}

