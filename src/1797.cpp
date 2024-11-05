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

struct Quadrado{
    iPair p1;
    iPair p2;
    iPair p3;
    iPair p4;
    Quadrado(iPair centro, double l){
        p1 = mp(centro.f + l/2, centro.s + l/2);
        p2 = mp(centro.f + l/2, centro.s - l/2);
        p3 = mp(centro.f - l/2, centro.s - l/2);
        p4 = mp(centro.f - l/2, centro.s + l/2);
    }
};

double distPontos(iPair p1, iPair p2){
    return sqrt(pow(p1.f - p2.f,2) + pow(p1.s - p2.s,2));
}
bool fora(Quadrado q1, iPair p, double D){
    if(q1.p4.f - D <= p.f && q1.p4.f > p.f){
        if(q1.p4.s + D >= p.s && q1.p4.s < p.s) return D < distPontos(q1.p4,p);
        if(q1.p3.s > p.s && q1.p3.s - D <= p.s) return D < distPontos(q1.p3,p);
    }
    if(q1.p1.f < p.f && q1.p1.f + D >= p.f){
        if(q1.p1.s + D >= p.s && q1.p1.s < p.s) return D < distPontos(q1.p1,p);
        if(q1.p2.s > p.s && q1.p2.s - D <= p.s) return D < distPontos(q1.p2,p);
    }
    return false;
}
bool dentro(Quadrado q1, iPair p, double D){
    if(q1.p4.f - D <= p.f && q1.p1.f + D >= p.f && q1.p4.s + D >= p.s && q1.p3.s - D <= p.s && !fora(q1,p,D) ){
        return true;
    }
    return false;
} // verifica se um ponto esta dentro do quadrado

int main() {
    _; double N, D;
    cin >> N >> D;
    vector<double> raio(N);
    vector<iPair> posicao(N);
    for (int i = 0; i < N; ++i) {
        int x,y;
        cin >> x >> y >> raio[i];
        posicao[i] = mp(x,y);
    }
    for(int i = 0; i < N-1; i++){
        Quadrado q1(posicao[i],raio[i]), q2(posicao[i+1],raio[i+1]);
        if(!(dentro(q1,q2.p1,D) || dentro(q1,q2.p2,D) || dentro(q1,q2.p3,D) || dentro(q1,q2.p4,D) ||
        dentro(q2,q1.p1,D) || dentro(q2,q1.p2,D) || dentro(q2,q1.p3,D) || dentro(q2,q1.p4,D)) ){
            cout << "OUCH" << endl;
            return 0;
        };
    }
    cout << "YEAH" << endl;
    return 0;

}
