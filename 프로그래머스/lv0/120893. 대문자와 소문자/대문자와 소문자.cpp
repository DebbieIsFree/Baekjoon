#include <string>
#include <vector>

using namespace std;

string solution(string str) {
    string answer = "";
    
    for(int i=0; i<str.length(); i++){
        if('A'<= str[i] && str[i] <= 'Z')
            answer += str[i] + 32;
        else
            answer += str[i] - 32;
    }
    
    return answer;
}