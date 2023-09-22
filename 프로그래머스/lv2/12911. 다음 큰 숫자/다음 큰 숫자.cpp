#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int ans = 0;
    int tmp = n;
    while(tmp > 0){    
        if(tmp % 2 == 1){
            ans += 1;
        }
        tmp /= 2;
    }
    
    
    while(1){
       n = n + 1;
       int tmp = n;
       int cnt = 0;
        while(tmp > 0){    
            if(tmp % 2 == 1){
                cnt++;
            }
            tmp /= 2;
        } 
        if(cnt == ans){
            break;
        }
    }
    
    answer = n;
    
    return answer;
}