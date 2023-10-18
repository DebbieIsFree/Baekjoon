#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());
    
    int idx = 0;
    int n = 0;
    int len = numbers.size();
    
    while(n < 10){
        if(numbers[idx] == n){
            idx++;
            n++;
        }
        else{
            answer += n;
            n++;
        }
    }
    
    return answer;
}