import java.util.*;
import java.io.*;


public class Main{
    
    static int N, M;
    static int result = 987_654;
    static int[][] map;
    static int[][] distance;
    static int[] target = new int[13];
    static List<Node> home = new ArrayList<>();
    static List<Node> store = new ArrayList<>();
    static HashSet<String> set = new HashSet<>();
    
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
	public static void main(String[] args) throws Exception {
	    st = new StringTokenizer(br.readLine());
	    N = Integer.parseInt(st.nextToken());
	    M = Integer.parseInt(st.nextToken());
	    map = new int[N][N];
	    
	    for(int i=0; i<N; i++){
	        st = new StringTokenizer(br.readLine(), " ");
	        for(int j=0; j<N; j++){
	            map[i][j] = Integer.parseInt(st.nextToken());
	            
	            if(map[i][j] == 1){
	                home.add(new Node(i, j));
	            }else if(map[i][j] == 2){
	                store.add(new Node(i, j));
	            }
	        }
	    }
	    
	    distance = new int[store.size()][home.size()];
	    for(int i=0; i<store.size(); i++){
	        Arrays.fill(distance[i], 987_654_321);
	    }
	    
	    for(int i=0; i<store.size(); i++){
	        for(int j=0; j<home.size(); j++){
	            Node s = store.get(i);
	            Node h = home.get(j);
	            distance[i][j] = Math.min(distance[i][j], (Math.abs(s.row - h.row) + Math.abs(s.col - h.col)) );
	        }
	    }
	    
	    for(int i=1; i<=M; i++){
	       // subset(i, 0, 0);
	       comb(i, 0, 0);
	    }
	    
	    System.out.println(result);
	}
	
	public static int calc(int cnt){
	    int sum = 0;
	    
	    for(int h=0; h<home.size(); h++){
	        int minDist = 987_654_321;
	        
	        for(int s=0; s<cnt; s++){
	            int storeIdx = target[s];
	            minDist = Math.min(minDist, distance[storeIdx][h]);
            }
            sum += minDist;
        }
	    return sum;
	}
	
	public static void comb(int goal, int cnt, int start){
	    if(cnt == goal){
	        result = Math.min(result, calc(goal));
	        return;
	    }
	    
	    for(int i=start; i<store.size(); i++){
	        target[cnt] = i;
	        comb(goal, cnt+1, i+1);
	        
	        comb(goal, cnt, i+1);
	    }
	}
	
	public static void subset(int goal, int cnt, int cur){
	    if(cnt == goal){
	        int idx = 0;
	        String str = "";
	        
	        for(int i=0; i<store.size(); i++){
	            if( (cur & (1 << i)) != 0 ){
	                str += i;
	                target[idx] = i;
	                idx++;
	            }
	        }
	        if(!set.contains(str)){
	            result = Math.min(result, calc(goal));
	            set.add(str);
	        }
	        return;
	    }
	    
	    for(int i=0; i<store.size(); i++){
	        if( (cur & (1 << i)) == 0){
	            subset(goal, cnt+1,  (cur | (1 << i)) );
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
