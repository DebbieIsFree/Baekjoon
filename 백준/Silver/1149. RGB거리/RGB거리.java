import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int [][] dp;
	static int [][] input;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N  = Integer.parseInt(br.readLine());
		
		dp = new int[N+1][3]; 
		input = new int[N+1][3]; 
		
		for(int i=1; i<=N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			input[i][0] = Integer.parseInt(st.nextToken());
			input[i][1] = Integer.parseInt(st.nextToken());
			input[i][2] = Integer.parseInt(st.nextToken());
		}
		
		dp[1][0] = input[1][0];
		dp[1][1] = input[1][1];
		dp[1][2] = input[1][2];
		
		for(int i=2; i<=N; i++) {
			dp[i][0] = Math.min(dp[i-1][1], dp[i-1][2]) + input[i][0] ;
			dp[i][1] = Math.min(dp[i-1][0], dp[i-1][2]) + input[i][1] ;
			dp[i][2] = Math.min(dp[i-1][0], dp[i-1][1]) + input[i][2] ;
		}
		
		System.out.println(Math.min(Math.min(dp[N][0], dp[N][1]), dp[N][2]));
		
	}// main
	
}
