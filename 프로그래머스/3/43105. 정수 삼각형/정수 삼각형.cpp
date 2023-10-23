#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> tri) {
    
    int dp[500][500];
    
    for(int i=0; i<500; i++){
        fill(dp[0], dp[0]+500, 0);
    }
    
    dp[0][0] = tri[0][0];
    
    for(int i=1; i<tri.size(); i++){        // level
        for(int j=0; j<tri[i].size(); j++){
            if(j == 0){
                dp[i][j] = dp[i-1][0] + tri[i][j];
            }
            else if(j == tri[i].size()-1){
                dp[i][j] = dp[i-1][j-1] + tri[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j-1]+tri[i][j], dp[i-1][j]+tri[i][j]);
            }
        }        
    }
    
    int answer = 0;
    int len = tri.size()-1;
    for(int i=0; i<tri.size(); i++){
        if(answer < dp[len][i])
            answer = dp[len][i];
    }
    
    return answer;
}