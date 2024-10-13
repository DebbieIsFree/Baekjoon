import java.io.*;
import java.util.*;



public class Main{
    
    static Integer N;
    static PriorityQueue<Long> pq = new PriorityQueue<>(Collections.reverseOrder());
    
	public static void main(String[] args) throws Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    N = Integer.parseInt(br.readLine());
	    
	    for(int i=0; i<N; i++){
	        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
	        
	        while(st.hasMoreTokens()){ 
	            pq.add(Long.parseLong(st.nextToken()));
	        }
	    }
	    
	    Integer cnt = 1;
	    
	    while(cnt < N && !pq.isEmpty()){
	        pq.remove();
	        cnt++;
	    }
	    
	    System.out.print(pq.peek());
	    
	}
}
