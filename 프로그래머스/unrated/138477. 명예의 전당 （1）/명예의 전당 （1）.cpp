#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> ans;
    vector<int> tops;
    
    int len = score.size();
    int small = min(k, len);
    
    for(int i=0; i<small; i++){
       tops.push_back(score[i]);
       sort(tops.begin(), tops.end());
       int tops_min = tops[0];
       ans.push_back(tops_min);
    }
    
    for(int i=small; i<score.size(); i++){
        sort(tops.begin(), tops.end());
        int tops_min = tops[0];
        // auto it = find(tops.begin(), tops.end(), tops_min);
        int tmin_idx = find(tops.begin(), tops.end(), tops_min) - tops.begin();
        
        if(tops_min < score[i]){
            tops[tmin_idx] =  score[i];
            // 왜 정렬해주고 min()을 해야할까? 
            sort(tops.begin(), tops.end());
            tops_min = tops[0];
            ans.push_back(tops_min);
        }else{
            ans.push_back(tops_min);
        }
    }
    return ans;
}
