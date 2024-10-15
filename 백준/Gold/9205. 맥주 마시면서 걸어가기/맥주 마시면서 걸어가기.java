import java.io.*;
import java.util.*;


public class Main{
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
	public static void main(String[] args) throws Exception {
	    st = new StringTokenizer(br.readLine());
	    int T = Integer.parseInt(st.nextToken());
	    
	    for(int t=0; t<T; t++){
	        st = new StringTokenizer(br.readLine());
	        int N = Integer.parseInt(st.nextToken());
	        
	        Vector<Node> v = new Vector<>();
	        Queue<Node> q = new ArrayDeque<>();
	        Boolean visited[] = new Boolean[N+2];
	        Arrays.fill(visited, false);
	        
	        // 출발지 (집)
	        st = new StringTokenizer(br.readLine());
	        int sx = Integer.parseInt(st.nextToken());
	        int sy = Integer.parseInt(st.nextToken());
	        v.add(new Node(sx, sy));
	        
	        // 편의점
	        for(int i=0; i<N; i++){
	            st = new StringTokenizer(br.readLine());
	            int x = Integer.parseInt(st.nextToken());
	            int y = Integer.parseInt(st.nextToken());
	            v.add(new Node(x, y));
	        }
	        
	        // 도착지
	        st = new StringTokenizer(br.readLine());
	        int dx = Integer.parseInt(st.nextToken());
	        int dy = Integer.parseInt(st.nextToken());
	        v.add(new Node(dx, dy));
	        
	        q.add(new Node(sx, sy));
	        visited[0] = true;
	        
	        if(Math.abs(dx - sx) + Math.abs(dy - sy) <= 1_000){
	            System.out.println("happy");
	            continue;
	        }
	        
	        while(!q.isEmpty()){
	            int tx = q.peek().x;
	            int ty = q.peek().y;
	            q.remove();
	            
	            for(int i=0; i<N+2; i++){
	                if(visited[i])
	                    continue;
	               
	                if(Math.abs(tx - v.elementAt(i).x) + Math.abs(ty - v.elementAt(i).y) <= 1_000){
	                    visited[i] = true;
	                    q.add(new Node(v.elementAt(i).x, v.elementAt(i).y));
	                }
	            }
	        }
	        
	        if(visited[N+1])
	            System.out.println("happy");
	        else
	            System.out.println("sad");
	    }
	}
	
	public static class Node{
	    int x;
	    int y;
	    
	    public Node(int x, int y){
	        this.x = x;
	        this.y = y;
	    }
	}
}
