import java.io.*;
import java.util.*;

public class Main{
    
    static Integer N, M, w = 0, b = 0;
    static Integer count = 0;
    static Boolean visited[][] = new Boolean[101][101];
    static Integer map[][] = new Integer[101][101];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    static Integer dr[] = {-1, 1, 0, 0};
    static Integer dc[] = {0, 0, -1, 1};
    
	public static void main(String[] args) throws Exception{
	    st = new StringTokenizer(br.readLine());
	    
	    N = Integer.parseInt(st.nextToken());
	    M = Integer.parseInt(st.nextToken());
	    
	    for(int r=0; r<M; r++){
	        String str = br.readLine();
	        Arrays.fill(visited[r], false);
	        
	        for(int c=0; c<N; c++){
	            if(str.charAt(c) == 'W'){
	                map[r][c] = 1;
	            }else{
	                map[r][c] = 0;
	            }
	        }
	    }
	    
	    // dfs
	    for(int r=0; r<M; r++){
	        for(int c=0; c<N; c++){
	            if(!visited[r][c]){
	                count = 1;
	                dfs(r, c);
	                if(map[r][c] == 1)
	                    w += count*count;
	                else 
	                    b += count*count;
	            }
	        }
	    }
	    
	   System.out.print(w + " " + b);
	}
	
	
	static void dfs(int row, int col){
        visited[row][col] = true;
        
        for(int i=0; i<4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            
            if(nr < 0 || nr >= M || nc < 0 || nc >= N || map[row][col] != map[nr][nc] || visited[nr][nc])
                continue;
            
            count++;
            dfs(nr, nc);
        }
    }
}
