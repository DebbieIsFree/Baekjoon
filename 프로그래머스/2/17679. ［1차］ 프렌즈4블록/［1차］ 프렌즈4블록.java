import java.util.*;

class Solution {
    
    static int[][] map;
    static boolean[][] check;
    
    public int solution(int m, int n, String[] board) {
        int answer = 0;
        
        map = new int[m][n];
        check = new boolean[m][n];
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                map[i][j] = board[i].charAt(j) - 'A';
            }
        }
        
        while(true){
            init(m, n);
            
            int cnt = search(m, n);
            answer += cnt;
            
            if(cnt == 0)
                break;
            
            down(m, n);
        }
        
        return answer;
    }
    
    public void init(int m, int n){
        for(int i=0; i<m; i++){
            Arrays.fill(check[i], false);
        }
    }
    
    public int search(int m, int n){
        int cnt = 0;
        
        for(int i=0; i<m-1; i++){
            for(int j=0; j<n-1; j++){
                if(map[i][j] == -100)
                    continue;
                
                int val = map[i][j];
                
                if(map[i+1][j] == val && map[i][j+1] == val && map[i+1][j+1] == val){
                    if(!check[i][j]){
                        check[i][j] = true;
                        cnt++;
                    }
                    if(!check[i+1][j]){
                        check[i+1][j] = true;
                        cnt++;
                    }
                    if(!check[i][j+1]){
                        check[i][j+1] = true;
                        cnt++;
                    }
                    if(!check[i+1][j+1]){
                        check[i+1][j+1] = true;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
    
    public void down(int m, int n){
        for(int col=0; col<n; col++){
            Queue<Integer> q = new ArrayDeque<>();
            
            for(int row=m-1; row>=0; row--){
                if(!check[row][col])
                    q.add(map[row][col]);
                
                map[row][col] = -100;
            }
            
            int r = m-1;
            
            while(!q.isEmpty()){
                map[r][col] = q.poll();
                r--;
            }
        }
    }
}