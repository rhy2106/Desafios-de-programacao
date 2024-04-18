#include <iostream>
#include <vector>
#include <string>
using namespace std;
int converter(char a){
    int num = static_cast<int>(a) - 48;
    return num;
}
int main(){
    int N;
    while(cin >> N){
        string A;
        vector<vector<int>> M;
        int tamanho, conta = 0, certo = 0;
        for(int i = 0; i < N; i++){
            M.resize(N);
            cin >> A;
            tamanho = A.size();
            for(int j = 0; j < tamanho; j++){
                int num = converter(A[j]);
                M[i].push_back(num);
            }
        }
        int total = 0;
        for(int i = 1; i < N; i++){
            int tmp =0;
            for(int ii = 1; ii <= i; ii++){
                int cont = 0;
                for(int j = 0;j < tamanho; j++){
                    if(M[i-ii][j] == M[i][j]){
                        conta += 1;
                        cont++;
                        if(tmp < conta){
                            tmp = conta;
                        }
                    } else{
                        break;
                    }
                }
                if(cont > 0){
                    conta = 0;
                }
            }
            total += tmp;
        }
        cout << total << endl;
    }
    return 0;
}
