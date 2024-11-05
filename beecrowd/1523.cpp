#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n1, n2;
    vector<pair<int,int>> carros;
    while(cin >> n1 >> n2, n1 != 0 && n2 != 0){
        carros.clear();
        int entrada, saida, erro = 0;
        for(int i = 0; i < n1; i++){
            scanf("%d %d", &entrada, &saida);
            if(!carros.empty()){
                for(int j = 0; j < carros.size(); j++){
                    if(carros[carros.size()-1].second <= entrada){
                        carros.pop_back();
                        j--;
                    } else if(carros[carros.size()-1].second > saida){
                        break;
                    } else {
                        erro = 1;
                        break;
                    }
                }
            }
            carros.push_back(make_pair(entrada,saida));
            if(carros.size() > n2){
                erro = 1;
            }
            if(i == n1 - 1){
                for(int j = 0; j < carros.size(); j++){
                    if(carros[carros.size()-1].second >= saida){
                        saida = carros[carros.size()-1].second;
                        carros.pop_back();
                        j--;
                    } else {
                        erro = 1;
                        break;
                    }
                }
            }
        }
        if(carros.size() == 0 && erro == 0){
            printf("Sim\n");
        } else {
            printf("Nao\n");
        }
    }
    return 0;
}
