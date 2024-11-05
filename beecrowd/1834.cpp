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

int produtoVetorial(iPair a, iPair b, iPair c) {
    return (b.f - a.f) * (c.s - a.s) - (b.s - a.s) * (c.f - a.f);
}
double distPontos(iPair p1, iPair p2){
    return sqrt(pow(p1.f - p2.f,2) + pow(p1.s - p2.s,2));
}

int main() {
    _; double xi, yi, xf, yf, N, morto = 0;
    iPair oeste = mp(0,0), leste = mp(0,0), comeco, fim;
    cin >> xi >> yi >> xf >> yf >> N;
    comeco = mp(xi,yi); fim = mp(xf,yf);
    for (int i = 0; i < N; ++i) {
        int x, y, p, d; cin >> x >> y >> p;
        d = produtoVetorial(comeco,fim,mp(x,y));
        if(d == 0) morto++;
        if(d > 0){
            oeste.f += 1;
            oeste.s += p;
        }
        if(d < 0){
            leste.f += 1;
            leste.s += p;
        }
    }
    cout << "Relatorio Vogon #35987-2" << endl;
    cout << fixed << setprecision(2) << "Distancia entre referencias: " << distPontos(comeco,fim) << " anos-luz" << endl;
    cout << "Setor Oeste:" << endl;
    cout << fixed << setprecision(0) << "- " << oeste.f << " planeta(s)" << endl;
    cout << "- " << oeste.s << " bilhao(oes) de habitante(s)" << endl;
    cout << "Setor Leste:" << endl;
    cout << "- " << leste.f << " planeta(s)" << endl;
    cout << "- " << leste.s << " bilhao(oes) de habitante(s)" << endl;
    cout << "Casualidades: " << morto << " planeta(s)" << endl;
    return 0;
}
