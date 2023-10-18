#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int solution(int num, int limit, int power) {
    int answer = 0;
    
    int arr[100001];
    
    fill(arr, arr+100001, 0);
    
    for(int i=1; i<=num; i++){
        int cnt = 0;
        for(int j=1; j<=sqrt(i); j++){
            
            if(i % j == 0 && (j*j != i))
                cnt += 2;
            else if(i % j == 0 && (j*j == i))
                cnt += 1;
        }
        arr[i] = cnt;
    }
    
    for(int i=1; i<=num; i++){
        if(arr[i] <= limit){
            answer += arr[i];
        }else{
            answer += power;
        }
    }
    
    
    return answer;
}



