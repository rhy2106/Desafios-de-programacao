#include <iostream>
#include <vector>

using namespace std;

bool verify(char tipo, char M){
    return (tipo == 'D' && M == 'E')||(tipo == 'E' && M == 'D');
}

int main(){
    int N, total = 0;
    while(cin >> N){
        cin.ignore();
        vector<pair<int,char>> M;
        for(int z = 0; z < N; z++){
            int num;
            char tipo;
            cin >> num >> tipo;
            if(M.empty()){
                M.push_back(make_pair(num,tipo));
            } else{
                for(int i = 0; i < M.size(); i++){
                    if(num == M[i].first && verify(tipo, M[i].second)){
                        total++;
                        M.erase(M.begin()+i);
                        break;
                    } else if(i == M.size()-1){
                        M.push_back(make_pair(num,tipo));
                        break;
                    }
                }
            }
            if(z == N - 1){
                cout << total << endl;
                total = 0;
                M.clear();
            }
        }
    }
    return 0;
}