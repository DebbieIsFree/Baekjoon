import java.util.*;

class Solution {
    
    static Queue<Integer> q1 = new ArrayDeque<>();
    static Queue<Integer> q2 = new ArrayDeque<>();
    
    public int solution(int[] queue1, int[] queue2) {
        int answer = 0;
        
        long q1sum = 0;
        long q2sum = 0;
        
        for(int i=0; i<queue1.length; i++){
            q1.add(queue1[i]);
            q2.add(queue2[i]);
        
            q1sum += queue1[i];
            q2sum += queue2[i];
        }
        
        if((q1sum + q2sum) % 2 != 0)
            return -1;
        
        long goal = (q1sum + q2sum) / 2;
        
        int cnt1 = 0;
        int cnt2 = 0;
        
        while(!q1.isEmpty() && !q2.isEmpty()){
            if(q1sum == goal)
                return answer;

            answer++;
            
            if(cnt1 >=300_000 || cnt2 >=300_000)
                return -1;
            
            if(q1sum > q2sum){
                int n = q1.poll();
                q2.add(n);
                q1sum -= n;
                q2sum += n;
                cnt1++;
            }else{
                int n = q2.poll();
                q1.add(n);
                q1sum += n;
                q2sum -= n;
                cnt2++;
            }
        }
        
        if(q1sum == goal)
            return answer;
        
        return -1;
    }
}