import java.util.*;

class Solution {
    
    static int sr = 0, sc = 0;
    static int er = 0, ec = 0;
    static int lr = 0, lc = 0;
    
    static int[] dr = {0, 0, -1, 1};
    static int[] dc = {-1, 1, 0, 0};
        
    public int solution(String[] maps) {
        int row = maps.length;
        int col = maps[0].length();
        
        int[][] map = new int[row][col];
        boolean[][] visited = new boolean[row][col];
        
        for(int i=0; i<row; i++){
            String str = maps[i];
            
            for(int j=0; j<col; j++){
                if(str.charAt(j) == 'X')
                    continue;
                
                if(str.charAt(j) == 'S'){
                    sr = i;
                    sc = j;
                }
                else if(str.charAt(j) == 'E'){
                    er = i;
                    ec = j;
                }
                else if(str.charAt(j) == 'L'){
                    lr = i;
                    lc = j;
                }
                
                map[i][j] = 1;
            }
        }
        
        int a1 = -1;
        int a2 = -1;

        Queue<Node> q = new ArrayDeque<>();
        
        visited[sr][sc] = true;
        q.add(new Node(sr, sc, 0));
        
        while(!q.isEmpty()){
            Node node = q.poll();
            int r = node.row;
            int c = node.col;
            int cnt = node.cnt;
            
            if(r == lr && c == lc){
                a1 = cnt;
                break;
            }
              
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr < 0 || nr >= row || nc < 0 || nc >= col || visited[nr][nc] || map[nr][nc] == 0)
                        continue;
                
                visited[nr][nc] = true;
                q.add(new Node(nr, nc, cnt+1));
            }
        }
        
        if(a1 == -1){
            return -1;
        }
        
        for(int i=0; i<row; i++){
            Arrays.fill(visited[i], false);
        }
        
        q.clear();
        visited[lr][lc] = true;
        q.add(new Node(lr, lc, a1));
        
        while(!q.isEmpty()){
            Node node = q.poll();
            int r = node.row;
            int c = node.col;
            int cnt = node.cnt;
            
            if(r == er && c == ec){
                a2 = cnt;
                break;
            }
            
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr < 0 || nr >= row || nc < 0 || nc >= col || visited[nr][nc] || map[nr][nc] == 0)
                        continue;
                
                visited[nr][nc]  = true; 
                q.add(new Node(nr, nc, cnt+1));
            }
        }
        
        if(a2 == -1)
            return -1;

        return a2;
    }
    
    public class Node{
        int row;
        int col;
        int cnt;
        
        public Node(int r, int c, int cnt){
            this.row = r;
            this.col = c;
            this.cnt = cnt;
        }
    }
}