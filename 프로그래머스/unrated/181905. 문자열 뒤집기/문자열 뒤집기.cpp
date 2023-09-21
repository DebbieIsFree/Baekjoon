#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string str, int s, int e) {
    string answer = "";
    string rev = "";
    string right = "";
    
    int len = str.length();
    
    for(int i=0; i<len; i++){
        if(i < s){
            answer += str[i];
        }
        else if(s <= i && i <= e){
            rev += str[i];
        }else{
            right += str[i];
        }
    }
    
    reverse(rev.begin(), rev.end());
    
    answer += (rev + right);
    
    return answer;
}