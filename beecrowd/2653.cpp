#include <iostream>
#include <set>
using namespace std;
 
int main() {
    string joia;
    set<string> Q;
    while(cin >> joia){
        Q.insert(joia);
    }
    cout << Q.size() << endl;
 
    return 0;
}