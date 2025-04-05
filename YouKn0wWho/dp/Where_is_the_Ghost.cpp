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
const int TARGET = 2520;
using namespace std;

int main() {
    clock_t tinicio, tfim;
    tinicio = clock();

    _;
	int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    vector<int> dp(TARGET, 0);

    for (int num : nums) {
        vector<int> new_dp = dp;
        for (int r = 0; r < TARGET; r++) {
            if (dp[r]) {
                int new_r = (1LL * r * num) % TARGET;
                new_dp[new_r] = (new_dp[new_r] + dp[r]) % MOD;
            }
        }
        new_dp[num % TARGET] = (new_dp[num % TARGET] + 1) % MOD;
        dp = new_dp;
//		for(int i = 0; i < dp.size(); i++) if(dp[i] != 0) cout << "[" << i << "," << dp[i] << "]";
//		cout << endl;
    }

    cout << dp[0] << "\n";
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}



