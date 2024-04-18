#include <iostream>
#include <stack>
using namespace std;

int main(){
    int N, erro;
    while(cin >> N, N != 0){
        stack<int> A;
        stack<int> E;
        int tmp;
        while(cin >> tmp, tmp != 0){
            A.push(tmp);
            for(int i = 1; i < N; i++){
                cin >> tmp;
                A.push(tmp);
            }
            erro = 0;
            int B = N;
            while(B > 0){
                if(!E.empty()){
                    if(E.top() == B){
                        E.pop();
                        B--;
                        continue;
                    }
                }
                if(!A.empty()){
                    if(A.top() == B){
                        A.pop();
                        B--;
                    } else {
                        E.push(A.top());
                        A.pop();
                    }
                } else if(E.top() != B){
                    erro = 1;
                    break;
                }
            }
            if(B == 0 && erro == 0 && A.empty()){
                cout << "Yes" << endl;
            } else{
                cout << "No" << endl;
            }
            while(!A.empty()){
                A.pop();
            }
            while(!E.empty()){
                E.pop();
            }
        }
        cout << endl;
    }
    return 0;
}