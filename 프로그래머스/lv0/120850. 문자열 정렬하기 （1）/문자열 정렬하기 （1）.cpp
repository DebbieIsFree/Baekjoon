#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string str) {
    vector<int> answer;
    
    for(int i=0; i<str.length(); i++){
        if(isdigit(str[i]))
            answer.push_back(str[i] - '0');
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}