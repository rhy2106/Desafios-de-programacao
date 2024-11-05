#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define iPair pair<int,int>

using namespace std;

double tamMin(int comeco, int fim, int C, int N){
    int dist;
    if(fim < comeco) dist = C - comeco + fim;
    else dist = fim - comeco;
    return dist;
}

int main(){
    _; int C, N;
    while(cin >> C >> N){
        bool erro = false;
        vector<double> posicao(N);
        vector<double> distP;
        for(int i = 0; i < N; i++) cin >> posicao[i];
        for(int i = 0; i < N; i++){
            int x = posicao[(N+i-1)%N];
            int y = posicao[(i+1)%N];
            int z = posicao[(i+2)%N];
            if(tamMin(x,y,C,N) <= C/N || tamMin(x,y,C,N) >= 3*C/N) erro = true;
            for(int j = 2; j < N-1; j++) if(N > 3 && tamMin(x,posicao[(i+j)%N],C,N) <= j*C/N) erro = true;
            if(tamMin(posicao[i],y,C,N) >= 2*C/N) erro = true;
            if(erro) break;
        }
        if(erro) cout << "N" << endl;
        else cout << "S" << endl;
    }
    return 0;
}
