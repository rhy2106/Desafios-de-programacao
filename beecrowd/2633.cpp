#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    vector<pair<string,int>> carnes;
    int N;
    while(cin >> N){
        for(int z = 0; z < N; z++){
            string carne;
            int indice;
            cin >> carne >> indice;
            carnes.push_back(make_pair(carne,indice));
        }
        sort(carnes.begin(),carnes.end(), [](const pair<string,int>& a, const pair<string,int>& b){
            return a.second < b.second;
        });
        for(int i = 0; i < carnes.size(); i++){
            cout << carnes[i].first;
            if(i != carnes.size()-1){
                cout << " ";
            }
        }
        cout << endl;
        carnes.clear();
    }
   return 0;
}