import java.io.*;
import java.util.*;

public class Main{
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int visited[][];
    static int map[][];
    static int R, C;
    static int[] dr = {0, 0, -1, 1};
    static int[] dc = {-1, 1, 0, 0};
    static int ans = 0;
    static int m = 0;
    
	public static void main(String[] args) throws Exception {
	    st = new StringTokenizer(br.readLine());
	    R = Integer.parseInt(st.nextToken());
	    C = Integer.parseInt(st.nextToken());
	    
	    visited = new int[R][C];
	    map = new int[R][C];
	    
	    for(int r=0; r<R; r++){
	        char arr[] = br.readLine().toCharArray();
	        for(int c=0; c<C; c++){
	            map[r][c] = (arr[c] == 'L') ? 1 : 0;
	        }
	    }
	    
	    for(int r=0; r<R; r++){
	        for(int c=0; c<C; c++){
	            if(map[r][c] == 1){
	                init();
	                bfs(r, c);
	                ans = Math.max(ans, m-visited[r][c]);
	            }
	        }
	    }
	    
	    System.out.print(ans);
	}
	
	static void init(){
	    m = 0;
	    
	    for(int r=0; r<R; r++){
            Arrays.fill(visited[r], 0);
    	}
	}
	
	static void bfs(int row, int col){
    	Queue<Node> q = new ArrayDeque<>();
    	
    	visited[row][col] = 1;
    	q.add(new Node(row, col));
    	
    	while(!q.isEmpty()){
    	    int cr = q.peek().row;
    	    int cc = q.peek().col;
    	    q.remove();
    	    
    	    for(int i=0; i<4; i++){
        	    int nr = cr + dr[i];
        	    int nc = cc + dc[i];
        	    
        	    if(nr < 0 || nr >=R || nc < 0 || nc >= C || visited[nr][nc] != 0 || map[nr][nc] != 1)
        	        continue;
        	   
        	    visited[nr][nc] = visited[cr][cc] + 1;
        	    q.add(new Node(nr, nc));
        	    
        	    if(m < visited[nr][nc])
        	        m = visited[nr][nc];
        	}
    	}
	}
	
	public static class Node{
	    int row;
	    int col;
	    
	    public Node(int row, int col){
	        this.row = row;
	        this.col = col;
	    }
	}
}
