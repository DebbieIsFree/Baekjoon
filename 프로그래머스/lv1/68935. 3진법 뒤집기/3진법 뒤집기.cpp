#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    string tmp = "";
    
    while(n > 0){
        tmp += n % 3;
        n /= 3;
    }
    
    reverse(tmp.begin(), tmp.end());
    
    for(int i=0; i<tmp.length(); i++){
        answer += tmp[i] * pow(3,i);    
    }
    
    
    return answer;
}


