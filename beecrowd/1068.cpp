#include <iostream>
using namespace std;
int main(){
    string M;
    while (getline(cin,M)){
        int N = 0, erro = 0;
        for(int i = 0; i < M.size(); i++){
            if(M[i] == '('){
                N++;
            } else if(M[i] == ')'){
                if(N == 0){
                    erro = 1;
                    break;
                } else{
                    N--;
                }
            }
        }
        if(N == 0 && erro == 0){
            cout << "correct" << endl;
        } else{
            cout << "incorrect" << endl;
        }
    }
    return 0;
}
