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
const int INF = 0x3f3f3f3f;
const ll int LINF = 0x3f3f3f3f3f3f3f3fll;

using namespace std;

vector<iPair> areas;
umap cameras;

int main(){
	_; int N, M;
    cin >> N >> M;
    int minc = INF, maxc = 0;
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y;
        if(x > y){
            cameras[i].pb(coberto.size());
            coberto.pb(mp(1,y));
            cameras[i].pb(coberto.size());
            coberto.pb(mp(x,N));
        }else{
            cameras[i].pb(coberto.size());
            coberto.pb(mp(x,y));
        }
    }
    if(!(minb >= minc && maxb <= maxc || (minc == 1 && maxc == N) || (minb == maxb))){
        cout << "impossible" << endl;
        return 0;
    }

    
	return 0;
}