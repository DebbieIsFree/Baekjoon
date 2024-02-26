import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, X, K;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		X = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
	
		int[] arr = new int[N+1];	// 0 : dummy
		arr[X] = 1;
		
		for(int j=1; j<=K; j++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			int tmp = arr[a];
			arr[a] = arr[b];
			arr[b] = tmp;
		}
		
		for(int h=1; h<=N; h++) {
			if(arr[h] == 1)
				sb.append(h).append("\n");
		}
		System.out.println(sb);
	} // main
	
}

