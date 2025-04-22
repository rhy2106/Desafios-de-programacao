#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define ull unsigned long long
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
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9 + 7;
using namespace std;

void igual(ull *a, ull* b){
	a[0] = b[0];
	a[1] = b[1];
	a[2] = b[2];
	a[3] = b[3];
}

ull div2a15(deque<ull>& nums,ull n){
	ull carry = 0;
	ull v = 100000000000000000ULL / n;
	for(ull& a : nums){
		ull c = a % n;
		a = (a / n);
		if(carry) a += carry*v;
		carry = c;
	}
	while(!nums.empty() && nums[0] == 0)
		nums.pop_front();
	return carry;
}

void mulmat(ull *a, ull *b){
	ull c[4];
	c[0] = (a[0]*b[0] % MOD + a[1]*b[2] % MOD)%MOD;
	c[1] = (a[0]*b[1] % MOD + a[1]*b[3] % MOD)%MOD;
	c[2] = (a[2]*b[0] % MOD + a[3]*b[2] % MOD)%MOD;
	c[3] = (a[2]*b[1] % MOD + a[3]*b[3] % MOD)%MOD;
	igual(a,c);
}

void matexp2(ull *m, ull n){
	ull res[4] = {1,0,0,1};
	while(n > 0){
		if(n % 2) mulmat(res,m);
		mulmat(m,m);
		n /= 2;
	}
	igual(m,res);
}

ull fastexp(ull b, ull e){
	ull r = 1;
	while(e > 0){
		if(r%2) r = r*b;
		b = b*b;
		e /= 2;
	}
	return r;
}

void matexp(ull *base, deque<ull>& n){
	ull res[4] = {1,0,0,1};
	ull exp = fastexp(5,15);
	while(n.size() >= 1){
		if(n.size() == 1 && n[0] == 0) break;
		ull resto = div2a15(n, exp);
		ull m2[4] = {base[0],base[1],base[2],base[3]};
		matexp2(m2,resto);
		mulmat(res,m2);
		matexp2(base, exp);
	}
	igual(base,res);
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	string s; cin >> s;
	deque<ull> nums;
	nums.clear();
	reverse(s.begin(), s.end());
	for(int i = 0; i < s.size(); i+=17){
		string b = s.substr(i,min(17,(int)s.size()-i));
		reverse(b.begin(),b.end());
		nums.pb(stoull(b));
	}
	reverse(nums.begin(),nums.end());
	ull m[4] = {1,1,1,0};
	if(s == "0"){
		cout << 0 << endl;
		return 0;
	}
	matexp(m,nums);
	cout << m[1] << endl;
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

