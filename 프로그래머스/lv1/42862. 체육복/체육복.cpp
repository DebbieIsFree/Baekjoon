#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    
    bool checked[31] = {0,};
    
    sort(lost.begin(), lost.end(), greater<int>());
    sort(reserve.begin(), reserve.end());
    
    vector<int> v;
    
    for(int i=0; i<lost.size(); i++){
        int idx = lost[i];
        auto it = find(reserve.begin(), reserve.end(), idx);
        if(it == reserve.end()){
            v.push_back(idx);
        }else{
            checked[idx] = true;
        }
    }
    
    for(int i=0; i<v.size(); i++){
        int lost_idx = v[i];
        
        auto prev = find(reserve.begin(), reserve.end(), lost_idx-1);
        auto next = find(reserve.begin(), reserve.end(), lost_idx+1);
        if(next != reserve.end()){
            if(lost_idx+1 <= 30 && !checked[lost_idx+1]){
                checked[lost_idx+1] = true;
                continue;
            }
                
        }
        if(prev != reserve.end()){
            if(lost_idx-1 >= 0 && !checked[lost_idx-1]){
                checked[lost_idx-1] = true;
                continue;
            }
        }
        answer--;
    }
    
    return answer;
}