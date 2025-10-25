#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long

using namespace std;

int main(){
    _;
	int n; cin >> n;
	vector<int> a(n, 0);
	for(int i = 0 ; i < n; i++){
		int x; cin >> x;
		a[i] = x;
	}
	vector<int> dp(8000+1,0);
	dp[4000] = 1;
	for(int c : a){
		if(c > 0)
			for(int i = 8000; i >= c; i--)
				dp[i] += dp[i-c];
		else
			for(int i = 0; i-c <= 8000; i++)
				dp[i] += dp[i-c];
	}
	int m; cin >> m;
	while(m--){
		int k; cin >> k;
		cout << dp[k+4000] << endl;
	}
    return 0;
}


