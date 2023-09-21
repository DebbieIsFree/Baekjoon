#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    bool checked[100001] = {0, };
    
    sort(section.begin(), section.end(), greater<int>());
    
    for(int i=0; i<section.size(); i++){
        int n = section[i];
        if(checked[n]){
            continue;
        }else{
            checked[n] = true;
        }
        for(int j=section[i]; j>=section[i]-(m-1) && j>=1; j--){
            checked[j] = true;
        }
        answer++;
    }
    
    return answer;
}