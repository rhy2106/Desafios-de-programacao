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
const ll int MOD = 998244353;
using namespace std;

const int N = 505;

bool dp[2][N][N];

int main(){
	_; int n, k; cin >> n >> k;
	dp[0][0][0] = 1;
	for(int i = 1; i <= n; i++){
		int now = i % 2;
		int last = 1 - now;
		int x; cin >> x;
		for(int j = 0; j <= k; j++)
			for(int y = 0; y <= j; y++){
				dp[now][j][y] = dp[last][j][y];
				if(j >= x){
				    dp[now][j][y] = max(dp[now][j][y],dp[last][j - x][y]);
				    if(y >= x) dp[now][j][y] = max(dp[now][j][y],dp[last][j - x][y - x]);
				}
			}
	}
	vector <int> res;
	for(int i = 0; i <= k; i++)
		if(dp[n % 2][k][i]) res.push_back(i);
	cout << res.size() << endl;
	for(int x : res) cout << x << " ";
	cout << endl;
}
