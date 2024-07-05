#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int size = brown + yellow;
    int sqt = sqrt(brown + yellow);
    
    for(int i=3; i<=sqt; i++){
        int j = size % i;
        if(j == 0 && size / i >= i){
            if((size / i -2) * (i-2) == yellow){
                answer.push_back(size / i);        
                answer.push_back(i);        
                break;
            }
        }
    }
    
    return answer;
}