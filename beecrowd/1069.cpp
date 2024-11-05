#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,abre = 0,diamante = 0;
    string M;
    vector<char> A;
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++){
        getline(cin,M);
        for(int j = 0; j < M.size(); j++){
            if(M[j] == '<' || M[j] == '>'){
                A.push_back(M[j]);
            }
        }
        for(int j = 0; j < A.size(); j++){
            if(A[j] == '<'){
                abre++;
            } else if(abre > 0 && A[j] == '>'){
                abre--;
                diamante++;
            }
        }
        cout << diamante << endl;
        A.clear();
        diamante = 0;
        abre = 0;
    }
    return 0;
}