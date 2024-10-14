import java.io.*;
import java.util.*;


public class Main{
    
    static Integer N, A, B;
    static Integer arr[];
    static Boolean visited[];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static Queue<Node> q = new ArrayDeque<Node>();
    
	public static void main(String[] args) throws Exception {
	    N = Integer.parseInt(br.readLine());
	    
	    arr = new Integer[N+1];
	    visited = new Boolean[N+1];
	    Arrays.fill(visited, false);
	    st = new StringTokenizer(br.readLine());
	    
	    for(int i=1; i<=N; i++){
	        arr[i] = Integer.parseInt(st.nextToken());
	    }
	    
	    st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        
        Boolean flag = false;
        q.add(new Node(A, 0));      // idx, cnt
        visited[A] = true;
        
        while(!q.isEmpty()){
            Node now = q.poll();
            
            if(now.idx == B){
                System.out.print(now.cnt);
                flag = true;
                break;
            }
            
            int i = 1;
            while(true){
                if(now.idx + arr[now.idx] * i <= N){
                    if(!visited[now.idx + arr[now.idx] * i]){
                        q.add(new Node(now.idx + arr[now.idx] * i, now.cnt+1));
                        visited[now.idx + arr[now.idx] * i] = true;
                    }   
                    i++;
                }else{
                    break;
                }
            }
            
            i = -1;
            while(true){
                if(now.idx + arr[now.idx] * i >= 1){
                    if(!visited[now.idx + arr[now.idx] * i]){
                        q.add(new Node(now.idx + arr[now.idx] * i, now.cnt+1));
                        visited[now.idx + arr[now.idx] * i] = true;
                    }   
                    i--;
                }else{
                    break;
                }
            }
        }
        
        if(!flag)
            System.out.print("-1");
	}
	
	public static class Node{
	    int idx;
	    int cnt;
	    
	    public Node(int idx, int cnt){
	        this.idx = idx;
	        this.cnt = cnt;
	    }
	}
}
