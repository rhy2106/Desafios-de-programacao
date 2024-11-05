#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define f first
#define s second
#define iPair pair<double,double>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

double calcDist(iPair p1, iPair p2){
    double dist = sqrt(pow(p1.f-p2.f,2) + pow(p1.s-p2.s,2));
    return dist = (dist > 0 ? dist : ((-1)*dist));
}

int main(){
    _;
    double x1,x2,y1,y2,r1,r2;
    while(cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2){
        double dist = calcDist(mp(x1,y1),mp(x2,y2));
        if(r1 >= dist + r2) cout << "RICO" << endl;
        else cout << "MORTO" << endl;
    }
    return 0;
}

