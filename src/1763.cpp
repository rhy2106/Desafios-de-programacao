#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    string linha;
    map<string,string> M;
    M["brasil"] = "Feliz Natal!";
    M["alemanha"] = "Frohliche Weihnachten!";
    M["austria"] = "Frohe Weihnacht!";
    M["coreia"] = "Chuk Sung Tan!";
    M["espanha"] = "Feliz Navidad!";
    M["grecia"] = "Kala Christougena!";
    M["estados-unidos"] = "Merry Christmas!";
    M["inglaterra"] = "Merry Christmas!";
    M["australia"] = "Merry Christmas!";
    M["portugal"] = "Feliz Natal!";
    M["suecia"] = "God Jul!";
    M["turquia"] = "Mutlu Noeller";
    M["argentina"] = "Feliz Navidad!";
    M["chile"] = "Feliz Navidad!";
    M["mexico"] = "Feliz Navidad!";
    M["antardida"] = "Merry Christmas!";
    M["canada"] = "Merry Christmas!";
    M["irlanda"] = "Nollaig Shona Dhuit!";
    M["belgica"] = "Zalig Kerstfeest!";
    M["italia"] = "Buon Natale!";
    M["libia"] = "Buon Natale!";
    M["siria"] = "Milad Mubarak!";
    M["marrocos"] = "Milad Mubarak!";
    M["japao"] = "Merii Kurisumasu!";
    while(getline(cin,linha)){
        if(M.find(linha) == M.end()){
            cout << "--- NOT FOUND ---" << endl;
        } else{
            cout << M[linha] << endl;
        }
    }
    
    return 0;
}