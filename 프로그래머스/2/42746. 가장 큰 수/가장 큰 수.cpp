#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2){
    // "7"과 "59"가 있을 때
    // "759", "597"이 되고
    // 문자열 비교 (ASCII순)에서는 
    // "597" < "759"이다.
    return s1+s2 > s2+s1;
}


string solution(vector<int> numbers) {
    string answer = "";
    
    // 이중 for문 불가

    vector<string> str;
    
    for(int n : numbers){
        str.push_back(to_string(n));
    }
    
    sort(str.begin(), str.end(), comp);
    
    
    if(str[0] == "0"){
        answer = "0";
        return answer;
    }
    
    for(string s : str){
        answer += s;
    }
    
    
    return answer;
}