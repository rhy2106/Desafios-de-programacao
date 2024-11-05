#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ld long double
#define mp make_pair
#define f first
#define s second
#define iPair pair<double,double>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

ld AreaMediana(ld m1, ld m2, ld m3){
    if(!(m1 + m2 > m3 && m1 + m3 > m2 && m2 + m3 > m1)) return -1;
    ld sp = (m1+m2+m3)/2;
    return (4.0/3.0) * sqrt( sp * (sp-m1) * (sp-m2) * (sp-m3));
}

int main(){
    _;
    ld m1,m2,m3;
    while(cin >> m1 >> m2 >> m3){
        cout << fixed << setprecision(3) << AreaMediana(m1,m2,m3) << endl;
    }
    return 0;
}
