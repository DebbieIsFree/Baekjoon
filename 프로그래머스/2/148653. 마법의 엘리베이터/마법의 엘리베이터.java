import java.util.*;

class Solution {
    
    static int maxSize = 100_000_000;
    static boolean[] visited = new boolean[maxSize + 1];
    static Queue<Node> q = new ArrayDeque<>();
    static int arr[] = new int[9];
    
    public int solution(int storey) {
        int answer = 0;
        
        arr[0] = 1;
        int tmp = 10;
        
        for(int i=1; i<=8; i++){
            arr[i] = tmp;
            tmp *= 10;
        }
        
        visited[storey] = true;
        q.add(new Node(storey, 0));
        
        while(!q.isEmpty()){
            Node node = q.poll();
            int cur = node.cur;
            int cnt = node.cnt;
            
            if(cur == 0){
                answer = cnt;
                break;
            }
            
            for(int i=8; i>=0; i--){
                int n1 = cur - arr[i];
                int n2 = cur + arr[i];
                
                if(n2 <= maxSize && !visited[n2]){
                    visited[n2] = true;
                    q.add(new Node(n2, cnt+1));
                }
                if(n1 >= 0 && !visited[n1]){
                    visited[n1] = true;
                    q.add(new Node(n1, cnt+1));
                }  
            }
        }
        return answer;
    }
    
    public class Node{
        int cur;
        int cnt;
        
        public Node(int cur, int cnt){
            this.cur = cur;
            this.cnt = cnt;
        }
    }
}