class Solution {
    
    public int solution(int m, int n, int[][] puddles) {
        int[][] dp = new int[n+1][m+1]; 
        
        for(int i=0; i<puddles.length; i++){
            int col = puddles[i][0];
            int row = puddles[i][1];
            dp[row][col] = -1;
        }
        
        dp[0][1] = 1;
        
        for(int row=1; row<=n; row++){
            for(int col=1; col<=m; col++){
                if(dp[row][col] == -1)
                    continue;
                
                if(dp[row-1][col] != -1)
                    dp[row][col] += dp[row-1][col];
                
                if(dp[row][col-1] != -1)
                    dp[row][col] += dp[row][col-1];
                
                dp[row][col] %= 1_000_000_007;
            }
        }
        
        return dp[n][m];
    }
}