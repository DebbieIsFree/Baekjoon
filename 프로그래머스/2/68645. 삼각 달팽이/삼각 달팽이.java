class Solution {
    
    static int[] dr = {1, 0, -1};
    static int[] dc = {0, 1, -1};
    
    public int[] solution(int n) {
        int size = n*(n+1)/2;
        
        int[] answer = new int[size];
        int[][] arr = new int[n][n];
        
        int cnt = 0;
        int tmp = 0;
        int dir = 0;
        int row = -1;    int col = 0;    int i = 1;
        
        while(tmp != n){
            cnt++;
            row = row + dr[dir];
            col = col + dc[dir];
            arr[row][col] = i++;
            
            if(cnt == n - tmp){
                dir = (dir+1) % 3;
                cnt = 0;
                tmp++;
            }
        }
        
        int idx = 0;
        for(int r=0; r<n; r++){
           for(int c=0; c<=r; c++){
               answer[idx] = arr[r][c];
               idx++;
           }
        }
        
        return answer;
    }
}