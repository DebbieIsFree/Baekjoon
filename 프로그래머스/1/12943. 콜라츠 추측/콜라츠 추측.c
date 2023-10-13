#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    long long num = n;
    
    while(1){
        if(num == 1){
            break;
        }
        if(answer >= 500){
            answer = -1;
            break;
        }
        if(num % 2 == 0){
            num = num / 2;
        }
        else{
            num = (num * 3) + 1;
        }
        answer++;
    }
    
    return answer;
}






