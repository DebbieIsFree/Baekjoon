import java.util.*;

class Solution {
    
    static int[][] arr;
    static boolean[][] visited;
    
    static int row = 0, col = 0;
    static int[] dr = {0, 0, -1, 1};
    static int[] dc = {-1, 1, 0, 0};
    static List<Integer> list = new LinkedList<>();
    
    public int[] solution(String[] maps) {
        row = maps.length;
        col = maps[0].length();
        
        arr = new int[row][col];
        visited = new boolean[row][col];
        
        for(int i=0; i<row; i++){
            char[] chArr = maps[i].toCharArray();
            
            for(int j=0; j<col; j++){
                if(chArr[j] == 'X'){
                    arr[i][j] = -100;
                }else{
                    arr[i][j] = chArr[j] - '0';
                }
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!visited[i][j] && arr[i][j] > 0){
                    visited[i][j] = true;
                    int n = dfs(i, j, arr[i][j]);
                    list.add(n);
                }
            }
        }
        
        if(list.size() == 0){
            int[] answer = new int[]{-1};
            return answer;
        }
        else{
            list.sort(new Comparator<Integer>(){
                @Override
                public int compare(Integer n1, Integer n2){
                    return n1 - n2;
                }
            });
            int[] answer = new int[list.size()];
            for(int i=0; i<list.size(); i++){
                answer[i] = list.get(i);
            }
            return answer;
        }
    }
    
    public int dfs(int r, int c, int sum){
        int tmp = sum;
        
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr < 0 || nr >= row || nc < 0 || nc >= col || visited[nr][nc] || arr[nr][nc] < 0)
                continue;
            
            visited[nr][nc] = true;
            tmp = Math.max(tmp, dfs(nr, nc, tmp + arr[nr][nc]));
        }
        
        return tmp;
    }
}