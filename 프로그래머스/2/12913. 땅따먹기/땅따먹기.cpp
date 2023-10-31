#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land){
    int answer = 0;

    int len = land.size();
    vector<vector<int>> dp(len, vector<int>(4, 0));
    
    for(int i=0; i<4; i++){
        dp[0][i] = land[0][i];
    }   
    
    for(int i=1; i<len; i++){
        for(int j=0; j<4; j++){
            int m = 0;
            for(int k=0; k<4; k++){
                if(j != k){
                    m = max(m, dp[i-1][k]);
                }
            }
            dp[i][j] = m + land[i][j];
        }
    }
    
    int m = 0;
    for(int i=0; i<4; i++){
       m = max(m, dp[len-1][i]);
    }
    
    answer = m;
    
    return answer;
}


