#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int M;
    cin >> M;
    for(int x = 0; x < M; x++){
        int N,K,id, altura, largura, comprimento,volume;
        vector<pair<int,int>> P;
        vector<int> saida;

        cin >> N >> K;

        for(int i = 0; i < N; i++){
            scanf("%d %d %d %d", &id, &altura, &largura, &comprimento);
            volume = altura * largura * comprimento;
            P.push_back(make_pair(id,volume));

        }
        sort(P.begin(),P.end(), [](const pair <int,int>& a, const pair <int,int>& b){
                if(a.second == b.second){
                    return a.first < b.first;
                }
                return a.second > b.second;
             });

        for(int i = 0; i < K; i++){
            saida.push_back(P[i].first);
        }

        sort(saida.begin(),saida.end());

        for(int i = 0; i < K; i++){
            printf("%i",saida[i]);
            if(i != K-1){
                printf(" ");
            }
        }
        printf("\n");
        saida.clear();
        P.clear();
    }
    return 0;
}
