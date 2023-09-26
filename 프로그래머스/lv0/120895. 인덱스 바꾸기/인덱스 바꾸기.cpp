#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string str, int num1, int num2) {
    string answer = "";
    
    for(int i=0; i<str.length(); i++){
        if(i == num1)
            answer += str[num2];
        else if(i == num2)
            answer += str[num1];
        else 
            answer += str[i];
    }
    
    
    
    return answer;
}