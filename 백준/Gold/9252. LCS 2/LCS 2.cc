#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main (){
    
    string str1, str2;
    cin >> str1 >> str2;
    
    for(int i=1; i<=str1.length(); i++){
        for(int j=1; j<=str2.length(); j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    // for(int i=1; i<=str1.length(); i++){
    //     for(int j=1; j<=str2.length(); j++){  
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    int row = str1.length();
    int col = str2.length();
    string ans = "";
    
    while(row >= 1 && col >= 1){
        if(dp[row][col] == dp[row-1][col]){
            row -= 1;
        }
        else if(dp[row][col] == dp[row][col-1]){
            col -= 1;
        }
        else{
            ans = str1[row-1] + ans;
            row -= 1;
            col -= 1;
        }
    }
    
    cout << dp[str1.length()][str2.length()] << "\n";
    if(dp[str1.length()][str2.length()] != 0)
        cout << ans;
    
    return 0;
}
