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
    double L,C,R1,R2;
    while(cin >> L >> C >> R1 >> R2, L != 0 || C != 0 || R1 != 0 || R2 != 0){
        if(R2 > R1) swap(R1,R2);
        if(C > L) swap(L,C);
        if(L >= 2*R1 && C >= 2*R1 && sqrt(pow(L - (R1 + R2),2) + pow(C - (R1 + R2),2)) >= R1+R2) cout << "S" << endl;
        else cout << "N" << endl;
    }
    return 0;
}
