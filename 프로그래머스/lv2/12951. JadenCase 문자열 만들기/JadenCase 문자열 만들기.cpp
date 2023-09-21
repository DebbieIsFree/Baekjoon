#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool flag = true;
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            answer += ' ';
            flag = true;
        }
        else if(isdigit(s[i])){
            flag = false;
            answer += s[i];
        }
        else if(flag == false){
            answer += tolower(s[i]);
        }
        else if(flag == true){
            answer += toupper(s[i]);
            flag = false;
        }
    }
    
    return answer;
}