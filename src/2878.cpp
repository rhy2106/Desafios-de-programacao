#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define lli long long int
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<lli,lli>
typedef tree<int, null_type, less_equal<lli>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

lli cntIntersections(vector<pair<lli, lli> > lines,lli N) {
	lli cnt = 0;
    ordered_multiset s;
    for (lli i = 0; i < N; i++) {
    	cnt += s.order_of_key(lines[i].second);
    	s.insert(lines[i].second);
	}
    return cnt;
}

lli cntAllIntersections(vector<pair<lli, lli> > lines,lli N) {
	sort(lines.begin(), lines.end(),greater<pair<lli, lli> >());
	lli totalCnt = 0;
	totalCnt += cntIntersections(lines, N);
	return totalCnt;
}

int main() {
    _; lli H, V, X, Y;
    while(cin >> X >> Y){
        cin >> H >> V;
        vector<iPair> hor(H); vector<iPair> ver(V);
        for(lli i = 0; i < H; i++) cin >> hor[i].f >> hor[i].s;
        for(lli i = 0; i < V; i++) cin >> ver[i].f >> ver[i].s;
        lli fatias = (V+1)*(H+1);
        fatias += cntAllIntersections(hor, hor.size());
        fatias += cntAllIntersections(ver, ver.size());
        cout << fatias << endl;
    }
    return 0;
}	
