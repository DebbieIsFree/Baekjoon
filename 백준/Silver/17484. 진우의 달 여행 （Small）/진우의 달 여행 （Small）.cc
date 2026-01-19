#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


int dr[] = {1, 1, 1};
int dc[] = {-1, 0, 1};

int map[6][6];
int dp[6][6][6];

// struct Info {
//     int prevDir;
//     int prevValue;
    
//     Info(){
//         this->prevDir = 1;
//         this->prevValue = 10000;
//     }
    
//     Info(int prevDir, int maxValue){
//         this->prevDir = prevDir;
//         this->prevValue = maxValue;
//     }
// };

// vector<vector<Info>> dp(6, vector<Info>(6));

int main(){
    int Row, Col;
    cin >> Row >> Col;

    for(int r=0; r<Row; r++){
        for(int c=0; c<Col; c++){
            cin >> map[r][c];
        }
    }
    
    for(int row=1; row<Row; row++){
        for(int col=0; col<Col; col++){
            for(int dir=0; dir<3; dir++){
                dp[row][col][dir] = 10000;
            }
        }
    }
    
    for(int col=0; col<Col; col++){
        for(int dir=0; dir<3; dir++){
            dp[0][col][dir] = map[0][col];
        }
    }
    
    for(int row=0; row<Row-1; row++){
        for(int col=0; col<Col; col++){
            for(int dir=0; dir<3; dir++){
                int prevDir = dir;
                int prevValue = dp[row][col][dir];    
                
                for(int nextDir=0; nextDir<3; nextDir++){
                    if(prevDir == nextDir)
                        continue;    
                        
                    int nrow = row + dr[nextDir];
                    int ncol = col + dc[nextDir];
                    
                    if(nrow < 0 || nrow >=Row || ncol < 0 || ncol >= Col)
                        continue;
                    
                    if(prevValue+map[nrow][ncol] < dp[nrow][ncol][nextDir]){
                        dp[nrow][ncol][nextDir] = prevValue + map[nrow][ncol];
                    }
                }
            }
        }    
    }
    
    int ans = 10000;
    
    for(int c=0; c<Col; c++){
        for(int d=0; d<3; d++){
            ans = min(ans, dp[Row-1][c][d]);    
        }
    }
    
    cout << ans;

    return 0;
}