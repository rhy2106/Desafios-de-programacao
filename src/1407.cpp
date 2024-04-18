#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, C, K;
    while(cin >> N >> C >> K, N != 0 && C != 0 && K != 0){
        vector<pair<int,int>> numeros;
        for(int i = 0; i < C*N; i++){
            int num;
            cin >> num;
            if(numeros.empty()){
                numeros.push_back(make_pair(num,1));
                continue;
            }
            for(int j = 0; j < numeros.size(); j++){
                if(num == numeros[j].first){
                    numeros[j].second++;
                    break;
                }
                if(j == numeros.size()-1){
                    numeros.push_back(make_pair(num,1));
                    break;
                }
            }
        }

        for(int i = K; i > 0; i--){
            for(int j = 0; j < numeros.size(); j++){
                if(i == numeros[j].first){
                    break;
                }
                if(j == numeros.size()-1){
                    numeros.push_back(make_pair(i,0));
                }
            }
        }

        sort(numeros.begin(),numeros.end(), [](const pair<int,int>& a, const pair<int,int>& b){
                if(a.second == b.second){
                    return a.first < b.first;
                }
                return a.second < b.second;
             });
        int menor = numeros[0].second;
        for(int i = 0; i < numeros.size();i++){
            if(numeros[i].second == menor){
                cout << numeros[i].first;
            }
            if(numeros[i+1].second == menor && i != numeros.size()-1){
                cout << " ";
                continue;
            }
        }
        cout << endl;
        numeros.clear();
    }
	return 0;
}
