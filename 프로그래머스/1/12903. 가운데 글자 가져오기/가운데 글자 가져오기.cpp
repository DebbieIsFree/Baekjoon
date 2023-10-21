#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int len = s.length();
    
    if(len % 2 == 0){
        int idx = len / 2 - 1;
        answer +=  s[idx];
        answer += s[idx+1];
    }
    else {
        int idx = len / 2;
        answer += s[idx];
    }
    
    return answer;
}