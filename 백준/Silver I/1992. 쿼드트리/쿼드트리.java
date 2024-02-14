import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static int N;
	static int[][] arr;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N][N];

		for (int i = 0; i < N; i++) {
			char[] input = br.readLine().toCharArray();
			for (int j = 0; j < N; j++) {
				arr[i][j] = input[j] - '0';
			}
		}

		System.out.println(func(0, 0, N));
	}

	static String func(int row, int col, int len) {
		if (len == 1) {
			return "" + arr[row][col];
		}

		int l = len / 2;
		String a = func(row, col, l);
		String b = func(row, col + l, l);
		String c = func(row + l, col, l);
		String d = func(row + l, col + l, l);
		
		String s = a+b+c+d;
		
		if(s.equals("0000") || s.equals("1111")) {
			return a;
		}else {
			return "(" + a + b + c + d + ")";
		}
		
	}
	
}
