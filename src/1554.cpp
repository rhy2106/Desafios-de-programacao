#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ld long double
#define mp make_pair
#define f first
#define s second
#define iPair pair<ld,ld>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

ld distPontos(iPair p1, iPair p2){
    return sqrt( pow(p1.f - p2.f, 2) + pow(p1.s - p2.s, 2) );
}

int main(){
    _;
    int C; cin >> C;
    for(int z = 0; z < C; z++){
        vector<iPair> bolas;
        vector<iPair> dist;
        int N, bola;
        cin >> N;
        for(int i = 0; i < N+1; i++){
            ld x, y;
            cin >> x >> y;
            bolas.push_back(mp(x,y));
        }
        for(int i = 1; i < N+1; i++){
            dist.push_back(mp(distPontos(bolas[0],bolas[i]),i));
        }
        sort(dist.begin(),dist.end());
        cout << fixed << setprecision(0) << dist[0].s << endl;
    }
    return 0;
}
