#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    
    for(int i=0; i<str1.length(); i++){
        for(int j=0; j<str2.length(); j++){
            if(str1[i] == str2[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    
    int n1 = str1.length();
    int n2 = str2.length();

    cout << dp[n1][n2];

    return 0;
}