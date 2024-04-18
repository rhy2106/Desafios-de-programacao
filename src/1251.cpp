#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<char,int>> M;

bool verify(char a){
    int erro = 0;
    for(int i = 0; i < M.size(); i++){
        if(a == M[i].first){
            M[i].second++;
            return true;
        } else if(i == M.size()-1){
            erro = 1;
        }
    }
    if(erro == 1){
        return false;
    }
    return false;
}
 
int main(){
    string linha;
    M.clear();
    while(getline(cin,linha)){
        if(!M.empty()){
            cout << endl;
        }
        M.clear();
        for(int i = 0; i < linha.size(); i++){
            char letra = linha[i];
            if(!M.empty()){
                if(!verify(letra)){
                    M.push_back(make_pair(letra,1));
                }
            } else{
                M.push_back(make_pair(letra,1));
            }
        }
        sort(M.begin(), M.end(), [](const pair <char,int>& a, const pair <char,int> b){
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second < b.second;
        });
        for(int i = 0; i < M.size(); i++){
            cout << (int)M[i].first << " " << M[i].second << endl;
        }
    }
    return 0;
}