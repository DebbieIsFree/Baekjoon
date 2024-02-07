import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		boolean[][] check = new boolean[100][100]; 
		
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x= Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			for(int j=y; j<y+10; j++) {
				for(int k=x; k<x+10; k++) {
					check[j][k] = true;
				}
			}
		}
		
		int cnt = 0;
		
		for(int j=0; j<100; j++) {
			for(int k=0; k<100; k++) {
				if(check[j][k])	cnt++;
			}
		}
		System.out.println(cnt);
	}
	
}
