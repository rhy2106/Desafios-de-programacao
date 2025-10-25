#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long

using namespace std;

int main(){
    _;
	vector<ull> triangulos(1e6 + 1,0);
	for(ull i = 1; i <= 1e6; i++){
		triangulos[i] = triangulos[i-1];
		triangulos[i] += i*(i+1)/2;
		triangulos[i] += (i/2)*(i/2+1);
		if(i%2 == 0) triangulos[i] -= i/2;
	}
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		cout << triangulos[n] << endl;
	}
    return 0;
}

