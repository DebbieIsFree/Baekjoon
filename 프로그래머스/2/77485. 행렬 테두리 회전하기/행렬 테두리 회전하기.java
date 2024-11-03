import java.util.*;

class Solution {
    
    static int[] dr = {0, 1, 0, -1};
    static int[] dc = {1, 0, -1, 0};
    static int[][] map;
    
    public int[] solution(int rows, int cols, int[][] queries) {
        int[] answer = new int[queries.length];
        map = new int[rows+1][cols+1];
        
        for(int r=1; r<=rows; r++){
            for(int c=1; c<=cols; c++){
                map[r][c] = (r-1)*cols + c;
            }
        }
        
        for(int i=0; i<queries.length; i++){
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];
            
            int r = r1;
            int c = c1;
            int dir = 0;
            int cnt = 0;
            int minN = 987_654_321;
            
            int[][] newMap = new int[rows+1][cols+1];
            
            for(int k=1; k<=rows; k++){
                newMap[k] = Arrays.copyOf(map[k], cols+1);
            }
            
            while(cnt < (r2-r1)*2 + (c2-c1)*2){
                cnt++;
                
                if((r == r1 && c == c2) || (r == r2 && c == c2) 
                   || (r == r2 && c == c1)){
                    dir = (dir + 1) % 4;
                }
                
                int nr = r + dr[dir];
                int nc = c + dc[dir];
                
                minN = Math.min(minN, map[nr][nc]);
                
                newMap[nr][nc] = map[r][c];
                r = nr;
                c = nc;
            }
            
            answer[i] = minN;
            
            for(int k=1; k<=rows; k++){
                map[k] = Arrays.copyOf(newMap[k], cols+1);
            }
        }
        
        return answer;
    }
}