#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string str = "";
    string tmp = "";
    
    for(int i=0; i<s.length(); i++){
        if(isdigit(s[i])){
            str += s[i];
        }
        if(!isdigit(s[i])){
            tmp += s[i];
        }
        if(tmp == "zero"){
            str += "0";
            tmp = "";
        }
        if(tmp == "one"){
            str += "1";
            tmp = "";
        }
        if(tmp == "two"){
            str += "2";
            tmp = "";
        }
        if(tmp == "three"){
            str += "3";
            tmp = "";
        }
        if(tmp == "four"){
            str += "4";
            tmp = "";
        } 
        if(tmp == "five"){
            str += "5";
            tmp = "";
        }
        if(tmp == "six"){
            str += "6";
            tmp = "";
        }
        if(tmp == "seven"){
            str += "7";
            tmp = "";
        }
        if(tmp == "eight"){
            str += "8";
            tmp = "";
        }
        if(tmp == "nine"){
            str += "9";
            tmp = "";
        }
    }
    
    answer = stoi(str);
    
    return answer;
}