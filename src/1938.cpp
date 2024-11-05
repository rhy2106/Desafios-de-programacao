#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ld long double
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>

using namespace std;

int main() {
    _; int N, cont = 0;
    cin >> N;
    vector<iPair> postes(N);
    map<iPair,int> posy;
    for(int i = 0; i < N; i++){
        int x, y; cin >> x >> y;
        postes[i] = mp(x,y);
    }
    sort(postes.begin(),postes.end(), [](const iPair a, const iPair b){return a.s < b.s;});
    for(int i = 0; i < N; i++) posy[postes[i]] = i;
    sort(postes.begin(),postes.end());
    for(int i = 0; i < N; i++){
        int up = INT_MAX, down = INT_MIN;
        for(int j = i+1; j < N; j++){
            if(posy[postes[i]] < posy[postes[j]]){
                if(postes[j].s > up) continue;
                up = postes[j].s;
                cont++;
                continue;
            }
            if(postes[j].s >= down){
                down = postes[j].s;
                cont++;
            }
        }
    }
    cout << cont << endl;
    return 0;
}