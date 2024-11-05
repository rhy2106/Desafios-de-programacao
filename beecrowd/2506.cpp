#include <iostream>

using namespace std;
int main(){
    int N;
    while(cin >> N){
        int total = 0, horario = 0;
        for(int z = 0; z < N; z++){
            int h,m,cc;
            cin >> h >> m >> cc;
            if(horario < h*60+m){
                horario = h*60+m;
            }
            while(horario % 30 != 0){
                horario++;
            }
            if(horario > h*60+m+cc){
                total++;
            }
            horario += 30;
        }
        cout << total << endl;
    }
    return 0;
}