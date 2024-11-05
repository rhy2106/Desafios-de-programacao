#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define f first
#define s second
#define iPair pair<double,double>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

double distPontos(iPair p1, iPair p2){
    return sqrt(pow(p1.f - p2.f,2) + pow(p1.s - p2.s,2));
}
double distPontoReta(iPair ponto, tuple<int,int,int> reta){
    double dist = (ponto.f*get<0>(reta) + ponto.s*get<1>(reta) + get<2>(reta)) / (sqrt(pow(get<0>(reta),2) + pow(get<1>(reta),2)));
    return dist = (dist >= 0 ? dist : ((-1)*dist));
}

int main(){
    _;
    int N;
    while(cin >> N, N != 0){
        vector<iPair> pontos;
        double distMin = 9999999;
        for(int i = 0; i < N; i++){
            double x, y;
            cin >> x >> y;
            pontos.push_back(mp(x,y));
        }
        for(int i = 0; i < pontos.size(); i++){
            for(int j = i+1; j < pontos.size(); j++){
                double tmp = distPontos(pontos[i],pontos[j]);
                if(distMin > tmp) distMin = tmp;
            }
        }
        if(distMin < 10000) cout << fixed << setprecision(4) << distMin << endl;
        else cout << "INFINITY" << endl;
    }
    return 0;
}
