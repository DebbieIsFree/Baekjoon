import java.util.*;


class Solution{
    
    static Queue<Integer> q = new ArrayDeque<>();
    
    public int solution(int n, int a, int b){
        int answer = 0;

        for(int i=1; i<=n; i++){
            q.add(i);
        }
        
        while(!q.isEmpty()){
            answer++;
            
            int sz = q.size();
            
            for(int i=0; i<sz/2; i++){
                int p1 = q.poll();
                int p2 = q.poll();
                
                if((p1 == a && p2 == b) || (p1 == b && p2 == a)){
                    return answer;
                }else{
                    if(p1 == a || p1 == b)
                        q.add(p1);
                    else if(p2 == a || p2 == b)
                        q.add(p2);
                    else
                        q.add(p1);
                }
            }
        }
        return answer;
    }
}