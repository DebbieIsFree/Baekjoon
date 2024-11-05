import java.util.*;

class Solution {
    
    static int answer;
    static int gCount, mCount;
    static int[] mineral;
    static int[][] cost = {
            {1, 1, 1},
            {5, 1, 1},
            {25, 5, 1}
        };
    
    public int solution(int[] picks, String[] minerals) {
        answer = Integer.MAX_VALUE;
        int availableCnt = 0;
        mCount = minerals.length;
        mineral = new int[mCount];
        
        for(int i=0; i<picks.length; i++){
            availableCnt += (picks[i] * 5);
        }
        for(int i=0; i<mCount; i++){
            mineral[i] = 2;
            if(minerals[i].equals("diamond"))
                mineral[i] = 0;
            else if(minerals[i].equals("iron"))
                mineral[i] = 1;
        }
        
        if(mCount > availableCnt){
            gCount = availableCnt / 5;
        }else{
            gCount = mCount / 5;
            if( (mCount % 5) > 0 )
                gCount += 1;
        }
        
        dfs(gCount, 0, picks, 0);
        
        return answer;
    }
    
    public void dfs(int goal, int cnt, int[] toolState, int sum){
        if(goal == cnt){
            answer = Math.min(answer, sum);
            return;
        }
        
        int[] toolStateCopy = Arrays.copyOf(toolState, toolState.length);
        
        for(int i=0; i<toolStateCopy.length; i++){
            if(toolStateCopy[i] > 0){
                toolStateCopy[i] -= 1;
                
                int val = 0;
                int startIdx = cnt * 5;
                for(int j=startIdx; j<startIdx+5 && j<mCount; j++){
                    int mIdx = mineral[j];
                    val += cost[i][mIdx];
                }
                
                dfs(goal, cnt+1, toolStateCopy, sum+val);
                toolStateCopy[i] += 1;
            }
        }
    }
}