#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    vector<vector<string>> v(26);
    
    for(int i=0; i<strings.size(); i++){
        int idx = strings[i][n] - 'a';
        v[idx].push_back(strings[i]);
    }
    
    for(int i=0; i<26; i++){
       sort(v[i].begin(), v[i].end());
    }
    
    for(int i=0; i<26; i++){
       for(int j=0; j<v[i].size(); j++){
           answer.push_back(v[i][j]);
       }
    }
    
    return answer;
}



