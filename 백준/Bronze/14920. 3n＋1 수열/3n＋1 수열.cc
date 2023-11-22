#include <iostream>

using namespace std;

int main(){
    
    int c1;  cin >> c1;
    
    int n = c1;
    int cnt = 1;
    
    while(n != 1){
        if(n % 2 == 0){
            n = n / 2;
        }else{
            n = 3*n + 1;
        }
        cnt++;
    }
    
    cout << cnt;

    return 0;
}
