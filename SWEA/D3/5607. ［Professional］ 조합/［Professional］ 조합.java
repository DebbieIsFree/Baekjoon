import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	
	static int T, N, R, P;
	static long ans;
	static long[] factMod;	// factMod[3] = 3 --> 3을 P로 나눈 나머지가 3
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		P = 1234567891;
		
		factMod = new long[1_000_001];
		
		// dp로 factMod를 채운다.
		factMod[0] = 1;
		
		for(int i=1; i<=1000000; i++) {
			factMod[i] = (factMod[i-1] * i) % P;
		}
		
		for(int t=1; t<=T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			R = Integer.parseInt(st.nextToken());
			
			// nCr :
			//         n!					         1
			//    -----------      ==>   n! *  -------------
			//	  (n-r)! * r!         		    (n-r)! * r!
			
			// ==> (n!%P)  *  ((n-r)! * r!) ^ P-2
			
			long top = factMod[N];
			long bottom = (factMod[N-R] * factMod[R]) % P;
			
			// 1 / bottom = bottom ^ (P-2)
			ans = (top * pow(bottom, P-2)) % P;
			sb.append("#").append(t).append(" ").append(ans).append("\n");
		}
		System.out.println(sb);
	}
	
	// Math.pow()  --> overflow 발생
	// 제곱하면서 계속 P로 나눈 나머지를 구하는 방식
	static long pow(long base, long exp) {
		if(exp == 0) return 1;
		else if(exp == 1) return base;
		
		long num = 1;
		
		while(exp > 0) {
			if(exp % 2 == 1) {	// 맨 마지막에 지수가 1이 될 때 num에 base 계산 값을 저장
				num *= base;	// 계산 중간에 exp가 홀수가 되면 뒤의 exp/2 
				num %= P;
			}
			
			base = (base * base) % P;
			exp /= 2;
			
		}
		return num;
	}

}
