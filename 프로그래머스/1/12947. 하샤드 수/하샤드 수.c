#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = true;
    
    int tmp = x;
    int div = 0;
    
    while(tmp > 0){
        div += (tmp % 10);
        tmp = tmp / 10;
    }
    
    if(x % div == 0){
        return answer;
    }
    answer = false;
    
    return answer;
}