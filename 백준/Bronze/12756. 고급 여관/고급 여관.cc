#include <iostream>

using namespace std;

int main(){
    
    int af, al;  cin >> af >> al;
    int bf, bl;  cin >> bf >> bl;
    
    while(1){
        if(al <=0 && bl <=0){
            cout << "DRAW";   break;
        }
        
        else if(al<=0){
            cout << "PLAYER B";  break;
        }
        else if(bl<=0){
            cout << "PLAYER A";  break;
        }
        al -= bf;
        bl -= af;
    }

    return 0;
}
