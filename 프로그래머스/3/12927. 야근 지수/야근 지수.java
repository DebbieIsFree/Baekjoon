import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        
        for(int i=0; i<works.length; i++){
            pq.add(works[i]);
        }
        
        while(!pq.isEmpty() && n > 0){
            int val = pq.poll();
            n--;
            
            if(val >= 1){
                pq.add(val-1);
            }
        }
        
        while(!pq.isEmpty()){
            int val = pq.poll();
            answer += val * val;
        }
        
        return answer;
    }
}