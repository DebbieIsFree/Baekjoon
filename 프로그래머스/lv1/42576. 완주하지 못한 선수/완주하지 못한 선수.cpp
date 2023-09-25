#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    
    for(int i=0; i<participant.size(); i++){
        string name = participant[i];
        m[name] += 1;
    }
    
    for(int i=0; i<completion.size(); i++){
        string name = completion[i];
        m[name] -= 1;
    }
    
    for(auto each : m){
        if(each.second == 1){
            answer = each.first;
            break;
        }
    }
    
    return answer;
}