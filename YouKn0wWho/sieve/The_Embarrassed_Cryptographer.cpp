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

ull div(deque<ull>& nums,ull n){
	ull carry = 0;
	ull v = 100000000000000000ULL / n;
	for(ull& a : nums){
		ull c = a % n;
		carry = c;
	}
	while(!nums.empty() && nums[0] == 0)
		nums.pop_front();
	return carry;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	vector<ull> primos(1e6+1,1);
	vector<ull> p;
	primos[0] = primos[1] = 0;
	p.pb(2);
	for(ull i = 3; i <= 1e6; i+=2){
		if(!primos[i]) continue;
		p.pb(i);
		for(ull j = i*i; j < 1e6; j+=2*i)
			primos[j] = 0;
	}
	string s;
	ull k;
	while(cin >> s >> k, s != "0" && k != 0){
		deque<ull> nums;
		nums.clear();
		reverse(s.begin(), s.end());
		for(int i = 0; i < s.size(); i+=17){
			string b = s.substr(i,min(17,(int)s.size()-i));
			reverse(b.begin(),b.end());
			nums.pb(stoull(b));
		}
		reverse(nums.begin(),nums.end());
		bool fraco = false;
		ull n;
		for(ull i : p){
			if(i > k || fraco) break;
			if(!div(nums,i)) fraco = true, n = i;
		}
		if(fraco) cout << "BAD " << n << endl;
		else cout << "GOOD" << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

