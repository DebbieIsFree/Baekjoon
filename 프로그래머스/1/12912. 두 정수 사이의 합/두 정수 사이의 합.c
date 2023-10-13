#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    
    int m = 0, n = 0;
    
    if(a > b){
        m = a;
        n = b;
    }
    else {
        m=b;
        n=a;
    }
    
    for(int i=n; i<=m; i++){
        answer += i;
    }
    
    
    return answer;
}