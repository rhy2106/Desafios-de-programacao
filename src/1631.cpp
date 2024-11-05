#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ld long double
#define mp make_pair
#define f first
#define s second
#define iPair pair<double,double>
#define iTuple tuple<double,double,double>
#define pqueue priority_queue<iPair,vector<iPair>, greater<iPair> >

using namespace std;

int produtoVetorial(iPair a, iPair b, iPair c) {
    return (b.f - a.f) * (c.s - a.s) - (b.s - a.s) * (c.f - a.f);
} // se retornar a positivo esta a esquerda do vetor, se retornar negativo a direita.
// se retornar 0 é colinear com o vetor

double distPontoReta(iPair ponto, double a, double b, double c, double raiz){
    double dist = (ponto.f*a + ponto.s*b + c)/raiz;
    return dist > 0 ? dist : -dist;
}

int main(){
    _;
    //time_t inicio,fim;
    //time(&inicio);
    int N;
    while(cin >> N, N != 0){
        vector<iPair> pontos(N);
        double distMin = 1e9;
        for(int i = 0; i < N; i++){
            cin >> pontos[i].f >> pontos[i].s;
        }
        for(int i = 0; i < N-1; i++){
            for(int j = i+1; j < N; j++){
                double esq = 0, dir = 0;
                double a = -(pontos[i].s - pontos[j].s);
                double b = (pontos[i].f - pontos[j].f);
                double c = -a*pontos[i].f - b*pontos[i].s;
                double raiz = sqrt(pow(a,2) + pow(b,2));
                for(int k = 0; k < N; k++){
                    if(i == k || j == k) continue;
                    int d = produtoVetorial(pontos[i],pontos[j],pontos[k]);
                    if(d == 0) continue;
                    double dist = distPontoReta(pontos[k],a,b,c,raiz);
                    if(d > 0) esq += dist;
                    else dir += dist;
                }
                if(esq != 0 || dir != 0) distMin = min(distMin,fabs(esq - dir));
                //cout << "esq: " << esq << " dir: " << dir << " " << fabs(esq - dir) << endl;
            }
        }
        if(distMin == 1e9) distMin = 0;
        cout << fixed << setprecision(3) << distMin << endl;
    }
    //time(&fim);
    //cout << fim-inicio << " segundos" << endl;
    return 0;
}
