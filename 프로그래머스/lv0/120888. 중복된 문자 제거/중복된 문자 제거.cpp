#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(string str) {
    string answer = "";
    unordered_map<char, int> m;
    
    for(int i=0; i<str.length(); i++){
        if(m.find(str[i]) == m.end()){
            m.insert({str[i], 1});
            answer += str[i];
        }
    }
    
    
    return answer;
}