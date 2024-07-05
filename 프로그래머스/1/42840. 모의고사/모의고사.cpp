#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v = {{1, 2, 3, 4, 5}, 
                         {2, 1, 2, 3, 2, 4, 2, 5},
                         {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
                        };

vector<int> answers;
vector<int> ans;      // {cnt, index}


void func(int idx){
    int n = v[idx].size();
    
    int cnt = 0;
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == v[idx][i%n])
            cnt++;
    }
    ans.push_back(cnt);
}

vector<int> solution(vector<int> input) {
    vector<int> answer;

    answers = input;
    
    for(int i=0; i<3; i++){
        func(i);
    }
    
    int maxVal = *max_element(ans.begin(), ans.end());
    
    for(int i=0; i<3; i++){
        if(ans[i] == maxVal){
            answer.push_back(i+1);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}