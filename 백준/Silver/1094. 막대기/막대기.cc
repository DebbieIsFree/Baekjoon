#include <iostream>
using namespace std;

// 2진수 (bit)를 이용해서 푸는 문제

int main(){
    
    int X;  cin >> X;
    int cnt = 0;
    
    while(X > 0){
        if(X % 2 == 1){
            cnt++;
        }
        
        X = X / 2;
    }
    
    cout << cnt;
    
    return 0;
}
