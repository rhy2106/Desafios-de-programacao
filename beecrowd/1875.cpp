#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ld long double
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<double,double>
#define iTuple tuple<double,double,double>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

int main() {
    _; int Z; cin >> Z;
    for(int z = 0; z < Z; z++){
        int N, red = 0, blue = 0, green = 0;
        cin >> N;
        for(int i = 0; i < N; i++){
            char t1,t2; cin >> t1 >> t2;
            if(t1 == 'R' && t2 == 'B') red += 1;
            if(t1 == 'R' && t2 == 'G') red += 2;
            if(t1 == 'B' && t2 == 'G') blue += 1;
            if(t1 == 'B' && t2 == 'R') blue += 2;
            if(t1 == 'G' && t2 == 'R') green += 1;
            if(t1 == 'G' && t2 == 'B') green += 2;
        }
        if(blue > red && blue > green) cout << "blue" << endl;
        else if(red > blue && red > green) cout << "red" << endl;
        else if(green > red && green > blue) cout << "green" << endl;
        else if(red == blue && red == green && blue == green) cout << "trempate" << endl;
        else if(red == blue || red == green || blue == green) cout << "empate" << endl;
    }
    return 0;
}
