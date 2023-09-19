#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            answer += s[i];
            continue;
        }
        // 대문자
        if(65<= s[i] && s[i] <= 90){
            char c = s[i] + n;
            while(c > 90){
                int add = (int)c - 91;
                c = 'A' + add;
            }
            answer += c;
        }
        // 소문자
        else if(97<= s[i] && s[i] <= 122){
            int num = s[i];
            int tmp = num + n;
            int add = n;
        
            if(tmp > 122){
                add = tmp - 123;
                tmp -= 123;
                char c = 'a' + add;
                answer += c;
            }
            else{
                answer += tmp;
            }
        }
    }

    return answer;
}

