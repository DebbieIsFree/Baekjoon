#include <string>
#include <vector>

using namespace std;

string solution(string number) {
    string answer = "";
    
    int len = number.length();
    
    for(int i=0; i<len-4; i++){
        answer += '*';
    }
    
    for(int i=len-4; i<len; i++){
        answer += number[i];
    }
    
    
    return answer;
}