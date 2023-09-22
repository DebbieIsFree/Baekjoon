#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    int idx = 1;
    
    while(idx < n){
        int sum = 0;
        for(int i=idx; i<n; i++){
            sum += i;
            if(sum == n){
                answer++;
                break;
            }
            if(sum > n){
                break;
            }
        }
        idx++;
    }
    
    return answer;
}