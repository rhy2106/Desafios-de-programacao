#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isletter(char c){
return (c >= '0' && c <= '9')||(c >= 'a' && c<= 'z')||(c >= 'A' && c <= 'Z');
}

bool isoperator(char c){
return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int prioridade(char c){
    if(c == '^'){
        return 3;
    } else if(c == '*' || c == '/'){
        return 2;
    } else if(c == '+' || c == '-'){
        return 1;
    } else{
        return -1;
    }
}

string ordem(string L){
    string final = "";
    vector<char> pilha;
    pilha.clear();
    for(char c : L){
        if(isletter(c)){
            final += c;
        } else if(isoperator(c)){
            if(!pilha.empty()){
                while(prioridade(pilha[pilha.size()-1]) >= prioridade(c)){
                    final += pilha[pilha.size()-1];
                    pilha.pop_back();
                }
            }
            pilha.push_back(c);
        } else if(c == '('){
            pilha.push_back(c);
        } else if(c == ')'){
            while(pilha[pilha.size()-1] != '('){
                    final += pilha[pilha.size()-1];
                    pilha.pop_back();
                  }
            pilha.pop_back();
        }
    }
    while(!pilha.empty()){
                final += pilha[pilha.size()-1];
                pilha.pop_back();
            }
    return final;
}

int main(){
    int N;
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++){
        string L;
        getline(cin,L);
        cout << ordem(L) << endl;
    }
    return 0;
}
