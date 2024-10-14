import java.io.*;
import java.util.*;

public class Main{
    static Integer N, M;
    static String s1 = "BWBWBWBW";
    static String s2 = "WBWBWBWB";
    static char arr[][] = new char[50][50];
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
	public static void main(String[] args) throws Exception {
	    st = new StringTokenizer(br.readLine(), " ");
	    N = Integer.parseInt(st.nextToken());
	    M = Integer.parseInt(st.nextToken());
	    
	    for(int i=0; i<N; i++){
	        String str = br.readLine();
	        
	        for(int j=0; j<M; j++){
	            arr[i][j] = str.charAt(j);
	        }
	    }
	    
	    int ans = 987654321;
	    for(int i=0; i<=N-8; i++){
	        for(int j=0; j<=M-8; j++){
	            ans = Math.min(ans, checkFunc('W', 'B', i, j));
	            ans = Math.min(ans, checkFunc('B', 'W', i, j));
	        }
	    }
	    
	    System.out.print(ans);
	}
	
	public static int checkFunc(char start, char second, int row, int col){
	    int cnt = 0;
	    int r = 0;
	    char tmp = start;
	    
	    for(int i=row; i<row+8; i++){
	        if(r % 2 == 0)
	            tmp = start;
	        else 
	            tmp = second;
	        
	        
	        for(int j=col; j<col+8; j++){
	            if(tmp != arr[i][j])
	                cnt++;
	            
	            if(tmp == 'W')
	                tmp = 'B';
	            else 
	                tmp = 'W';
	        }
	        r++;
	    }
	    return cnt;
	}
}
