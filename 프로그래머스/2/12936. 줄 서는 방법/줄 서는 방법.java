import java.util.*;

class Solution {
    
    static long cnt = 0;
    static boolean[] visited;
    static int[] order;
    static int[] answer;
    static int idx = 1;
    
    public int[] solution(int n, long k) {
        visited = new boolean[n+1];
        order = new int[n];
        answer = new int[n];
        
        backtracking(n, k, 0);
        
        return answer;
    }
    
    public long calc(int n){
        if(n <= 2)
            return 0;
        
        long tmp = 1;
        for(int i=2; i<=n-1; i++){
            tmp = tmp * i;
        }
        return tmp;
    }
    
    public void backtracking(int n, long k, int depth){
        if(cnt == k)
            return;
        
        if(depth == n){
            cnt++;
            
            if(cnt == k){
                for(int i=0; i<n; i++){
                    answer[i] = order[i];
                }
                return;
            }
        }
        
        long val = calc(n - depth);
        
        for(int i=1; i<=n; i++){
            if(visited[i])
                continue;
            
            if(val > 0 && cnt + val < k){
                cnt += val;
                continue;
            }
            
            visited[i] = true;
            order[depth] = i;
            backtracking(n, k, depth+1);
            visited[i] = false;
        }
    }
}