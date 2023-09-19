#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int flag = false;
    int idx = 0;
    for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                flag = true;
                answer += ' ';
                idx = 0;
                continue;
            }
            if(flag && s[i] != ' '){
                idx = 0;
                flag = false;
            }
        
            if(idx % 2 == 0){ // 대문자
                if(97 <= s[i] && s[i] <= 122){
                    answer += (s[i]-32);
                }
                else if(65 <= s[i] && s[i] <= 90){
                    answer += s[i];
                }
                idx++;
            }else{  // 소문자
                if(97 <= s[i] && s[i] <= 122){
                    answer += s[i];
                }
                else if(65 <= s[i] && s[i] <= 90){
                     answer += (s[i]+32);
                }
                idx++;
            }
    }  
     
    
    
    return answer;
}