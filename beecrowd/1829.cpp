#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define ld long double
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
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _; 
	vector<ld> logfat(10000+1,0);
	for(int i = 2; i <= 10000; i++)
		logfat[i] = logfat[i-1] + log(i);
	int tt, t = 0; cin >> tt;
	vector<string> rodadas(tt);
	int l = 0, p = 0;
	while(tt--){
		string c1,c2; cin >> c1 >> c2;
		int b, e;
		int fat = stoi( c2.substr(0,c2.size()-1));
		b = stoi( c1.substr(0,c1.find('^')) );
		e = stoi( c1.substr(c1.find('^')+1,c1.size()) );
		ld fatorial = logfat[fat] / log(b);

		if( e > fatorial){
			rodadas[t] = "Rodada #" + to_string(t+1) + ": Lucas foi o vencedor";
			l++;
		}else{
			rodadas[t] = "Rodada #" + to_string(t+1) + ": Pedro foi o vencedor";
			p++;
			if(fatorial == e) l++;
		}
		t++;
	}
    if(l > p) cout << "Campeao: Lucas!" << endl;
	else if(l < p) cout << "Campeao: Pedro!" << endl;
	else cout << "A competicao terminou empatada!" << endl;
	for(string a : rodadas) cout << a << endl;
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

