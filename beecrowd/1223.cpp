#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define f first
#define s second
#define iPair pair<double,double>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

double distPontoReta(iPair ponto, tuple<int,int,int> reta){
    double dist = (ponto.f*get<0>(reta) + ponto.s*get<1>(reta) + get<2>(reta)) / (sqrt(pow(get<0>(reta),2) + pow(get<1>(reta),2)));
    return dist = (dist >= 0 ? dist : ((-1)*dist));
}

int main(){
    _;
    int N, L, H;
    while(cin >> N){
        vector<iPair> aletas;
        vector<tuple<double,double,double>> retas;
        double distMin = 9999999;
        cin >> L >> H;
        aletas.resize(N);
        retas.resize(N);
        for(int i = 0; i < N; i++){
            double yi, xf, yf, a,b,c;
            iPair p1,p2;
            cin >> yi >> xf >> yf;
            p1 = mp(xf,yf);
            aletas[i] = p1;
            if(i % 2 == 0) p2 = mp(0,yi);
            else p2 = mp(L,yi);
            a = p1.s - p2.s;
            b = p1.f - p2.f;
            c = b*yf - a*xf;
            retas[i] = {-a,b,-c};
        }
        for(int i = 0; i < N; i++){
            double tmp;
            tuple<double,double,double> abc;
            if(i % 2 == 0) abc = {L,0,-aletas[i].s};
            else abc = {1,0,-aletas[i].s};
            tmp = distPontoReta(aletas[i], abc);
            if(tmp < distMin) distMin = tmp;
            if(i != N-1){
                tmp = distPontoReta(aletas[i], retas[i+1]);
                if(tmp < distMin) distMin = tmp;
            }
        }
        cout << fixed << setprecision(2) << distMin << endl;
    }
    return 0;
}
