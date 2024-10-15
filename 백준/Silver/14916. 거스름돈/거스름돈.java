import java.io.*;
import java.util.*;

public class Main{
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
	public static void main(String[] args) throws Exception {
	    st = new StringTokenizer(br.readLine());
	    int N = Integer.parseInt(st.nextToken());
    
        int dp[] = new int[N+1];
        Arrays.fill(dp, 987654321);
    
        if(N == 1 || N == 3){
            System.out.print("-1");
            return;
        }
        
        if(N == 2){
            System.out.print("1");
            return;
        }
        
        dp[0] = 0;
        dp[2] = 1;
        dp[4] = 2;
    
        for(int i=5; i<=N; i++){
            dp[i] = Math.min(dp[i-2], dp[i-5]) + 1;
        }
        
        if(dp[N] >= 987654321)
            System.out.print("-1");
        else    
            System.out.print(dp[N]);
	}
}
