#include <iostream>

using namespace std;

int main(){
    
    
    
    int given, goal, underZero, zero, overZero;
    cin >> given >> goal >> underZero >> zero >> overZero;
    
    int t = 0;
    
    while(given < 0){
        t += underZero;
        given += 1;
    }
    
    if(given == 0)
        t += zero;
    
    while(given < goal){
        t += overZero;
        given += 1;
    }
    
    cout << t;

    return 0;
}



