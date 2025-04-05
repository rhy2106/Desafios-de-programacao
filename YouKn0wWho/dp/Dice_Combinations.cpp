#include <bits/stdc++.h>
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set<int>
#define umap unordered_map<int,vector<int>>
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

int main(){
	_; ll int N; cin >> N;
	ll int mod = 1000000007;
	vector<ll int> mapa;
	mapa.pb(1);
	for(ll int i = 0; i <= N; i++){
		if(mapa.size() > i) continue;
		mapa.pb(0);
		for(int j = 1; j < 7; j++){
			if(i - j < 0) break;
			mapa[i] = (mapa[i] + mapa[i-j]) % mod;
		}
	}
	cout << mapa[N] << endl;
	return 0;
}
