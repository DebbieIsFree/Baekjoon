#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    long long s = sqrt(n);
    
    if(s*s == n){
        answer = (s+1)*(s+1);
    }else{
        answer = -1;
    }
    
    
    return answer;
}