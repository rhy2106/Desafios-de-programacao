#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string linha;
    while(getline(cin,linha)){
        vector <pair<string,int>> M;
        M.clear();
        int cont = 1;
        for(int i = 0; i < linha.size(); i++){
            if(linha[i] == linha[i-1] && cont < 9){
                cont++;
                M.pop_back();
                M.push_back(make_pair(linha.substr(i,1),cont));
            } else{
                cont = 1;
                M.push_back(make_pair(linha.substr(i,1),cont));
            }
        }
        for(int i = 0; i < M.size(); i++){
            if(M[i].first == "1" && M[i].second == 1){
                M[i].first = "11";
            }
        }
        for(int i = 0; i < M.size(); i++){
            if(M[i].second != 1){
                cout << M[i].second << M[i].first;
            }
            else{
                if(M[i-1].second != 1){
                    cout << M[i].second;
                }
                cout << M[i].first;
                if(M[i+1].second != 1 ||((i == M.size()-1)&&M[i].second == 1)){
                    cout << M[i].second;
                }
            }
        }
        cout << endl;
    }
    return 0;
}