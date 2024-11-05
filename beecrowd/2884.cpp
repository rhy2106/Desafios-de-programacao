#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main() {
    int I, L;
    cin >> I >> L;
    vector<int> lampadas;
    vector<string> interruptor;
    for(int i = 0; i < L; i++){
        lampadas.push_back(0);
    }
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int indice;
        cin >> indice;
        lampadas[indice-1] = 1;
    }
    cin.ignore();
    for(int i = 0; i < I; i++){
        string linha;
        getline(cin, linha);
        interruptor.push_back(linha);
    }
    int sim = 0, total = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < I; j++){
            stringstream s(interruptor[j]);
            string num;
            int cont = 0;
            while(s >> num){
                if(cont == 0){
                    cont++;
                    continue;
                }
                if(lampadas[stoi(num)-1] == 0){
                    lampadas[stoi(num)-1] = 1;
                } else{
                    lampadas[stoi(num)-1] = 0;
                }
            }
            if(sim == 0){
                total++;
            }
            for(int ii = 0; ii < L; ii++){
                if(lampadas[ii] == 1){
                    break;
                }
                if(lampadas[ii] == 0 && ii == L-1){
                    sim = 1;
                }
            }
        }
        if(sim == 1){
            break;
        }
    }
    if(sim == 0){
        total = -1;
    }
    cout << total << endl;
    return 0;
}
