#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set<int>
#define umap unordered_map<int,vector<int>>
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
#define gcd( x, y )  __gcd( x, y ) // menor divisor comum

const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;
const ll int MOD = 1000000007;

using namespace std;

int main() {
    clock_t tinicio, tfim;
    tinicio = clock();

    _; int Z; cin >> Z;
    while(Z--){
        int N; cin >> N;
		vector<int> boss(N);
		vector<int> ele(N+1);
		vector<int> eu(N+1);
		for(int i = 0; i < N; i++) cin >> boss[i];
		ele[N] = eu[N] = 0;
		for(int i = N-1; i >= 0; i--){
			ele[i] = eu[i + 1] + boss[i];
			if(i + 2 <= N) ele[i] = min(ele[i], eu[i+2] + boss[i] + boss[i+1]);
			eu[i] = ele[i+1];
			if(i + 2 <= N) eu[i] = min(eu[i], ele[i+2]);
		}
		cout << ele[0] << endl;
    }

    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}



