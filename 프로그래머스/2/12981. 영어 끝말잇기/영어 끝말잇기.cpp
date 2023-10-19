#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    int people[11] = {0,};
    
    vector<string> v;
    
    char last = words[0][0];
    
    for(int i=0; i<words.size(); i++){
        int idx = (i+1) % n;
        if(idx == 0) idx = n;
        people[idx] += 1;
        
        auto it = find(v.begin(), v.end(), words[i]);
        
        if(it != v.end()){
            answer.push_back(idx);
            answer.push_back(people[idx]);
            break;
        }
        else {
            int len = words[i].length()-1;
            if(last == words[i][0]){
                v.push_back(words[i]);
                last = words[i][len];
            }
            else {
                answer.push_back(idx);
                answer.push_back(people[idx]);
                break;
            }
        }
    }
    
    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    

    return answer;
}







