import java.util.*;

class Solution {
    
    static boolean[] visited;
    static Queue<Node> q = new ArrayDeque<>();
    
    public int solution(int x, int y, int n) {
        visited = new boolean[y+1];
        
        visited[x] = true;
        q.add(new Node(x, 0));
        
        while(!q.isEmpty()){
            Node node = q.poll();
            int cur = node.cur;
            int cnt = node.cnt;
            
            if(cur == y){
                return cnt;
            }
            
            if(cur+n <=y && !visited[cur+n]){
                visited[cur+n] = true;
                q.add(new Node(cur+n, cnt+1));
            }
            if(cur*2 <=y && !visited[cur*2]){
                visited[cur*2] = true;
                q.add(new Node(cur*2, cnt+1));
            }
            if(cur*3 <=y && !visited[cur*3]){
                visited[cur*3] = true;
                q.add(new Node(cur*3, cnt+1));
            }
        }
        
        return -1;
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