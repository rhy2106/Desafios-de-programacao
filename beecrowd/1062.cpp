#include <iostream>
#include <stack>
using namespace std;

int main(){
    int N;
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
                    break;
                }
            }
            if(B == 0){
                cout << "Yes" << endl;
            } else{
                cout << "No" << endl;
            }
        }
        cout << endl;
    }
    return 0;
}