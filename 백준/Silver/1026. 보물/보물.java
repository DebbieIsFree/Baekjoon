import java.io.*;
import java.util.*;

public class Main{
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static PriorityQueue<Integer> q1 = new PriorityQueue<>();
    static PriorityQueue<Integer> q2 = new PriorityQueue<>(Collections.reverseOrder());
    
    
	public static void main(String[] args) throws Exception {
	    st = new StringTokenizer(br.readLine());
	    int N = Integer.parseInt(st.nextToken());
	    
	    st = new StringTokenizer(br.readLine(), " ");
	    for(int i=0; i<N; i++){
	        q1.add(Integer.parseInt(st.nextToken()));
	    }
	    
	    st = new StringTokenizer(br.readLine(), " ");
	    for(int i=0; i<N; i++){
	        q2.add(Integer.parseInt(st.nextToken()));
	    }
	    
	    int ans = 0;
	    while(!q1.isEmpty() && !q2.isEmpty()){
	        ans += q1.poll() * q2.poll();
	    }
	    
	    System.out.print(ans);
	}
}
