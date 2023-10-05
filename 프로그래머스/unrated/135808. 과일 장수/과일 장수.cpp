#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), greater<int>());
    
    int cnt = 0;
    int min_val = 9999;
    for(int i=0; i<score.size(); i++){
        cnt++;
        if(score[i] < min_val){
            min_val = score[i];
        }
        if(cnt == m){
            answer += min_val * m;
            cnt = 0;
        }
    }
    
    return answer;
}

