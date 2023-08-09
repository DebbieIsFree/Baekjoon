#include <iostream>
using namespace std;

// 구현 문제
// 대각선 위로 증가하는 방향 or 대각선 아래로 감소하는 방향 (== 홀/짝수로 구분)
// 2가지로 구분


int main(){
    int X;  cin >> X;
    int max_num = 0;
    int line = 0;
    
    for(int i=1; i<=X; i++){
        if(max_num < X){
            max_num += i;
            line = i;
        }
        else{
            break;
        }
    }
    
    int top = 0;
    int bottom = 0;
    int start = max_num - line + 1;
  
    
    if(line % 2 == 1){
        top = line;
        bottom = 1;
        while(start != X){
            top--;
            bottom++;
            start++;
        }
    }else{
        top = 1;
        bottom = line;
       while(start != X){
            top++;
            bottom--;
            start++;
        }
    }
    
    cout << top << "/" << bottom--;

    return 0;
}
