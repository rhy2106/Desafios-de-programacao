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
    long long int N, M; int Z = 0;
    while(cin >> N >> M){
        Z++; cout << "Molecula #" << Z << ".:." << endl;
        long long int arestas = (N*5 + M*6)/2;
        long long int vertices = 2 + arestas - N - M;
        cout << "Possui " << vertices << " atomos e " << arestas << " ligacoes" << endl << endl;
    }
    return 0;
}
