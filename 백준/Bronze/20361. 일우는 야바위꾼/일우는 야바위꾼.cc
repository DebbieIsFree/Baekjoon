#include <iostream>

using namespace std;

int main(){
    
    int N, X, K;
    cin >> N >> X >> K;
    
    
    
    while(K--){
        int a, b;
        cin >> a >> b;
        
        if(a == X) {
            X = b;   
        }
        else if(b == X){
           X = a;
        }
    }
    
    cout << X;
    
    return 0;
}
