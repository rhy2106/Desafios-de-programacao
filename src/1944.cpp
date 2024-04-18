#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<string> pilha;

bool verify(string linha){
    string face = pilha.top();
    int erro = 0;
    for(int i = 0; i < linha.size(); i++){
        if(face[6-i] != linha[i]){
            erro = 1;
            break;
        } else{
            erro = 0;
        }
    }
    if(erro == 1){
        return false;
    } else{
        return true;
    }
}
// FACE ECFA ACEF FECA AFCE
int main(){
    int N, total = 0;
    cin >> N;
    cin.ignore();
    while(!pilha.empty()){
        pilha.pop();
    }
    for(int z = 0; z < N; z++){
        string linha;
        getline(cin,linha);
        if(pilha.empty()){
            pilha.push("F A C E");
        }

        if(verify(linha)){
            pilha.pop();
            total++;
        } else{
            pilha.push(linha);
        }
    }
    cout << total << endl;
    return 0;
}