import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static char[][] map1, map2;
	static int cnt;
	static int rgb;
	static boolean[][] visited;
	static int[] dr = { -1, 1, 0, 0 };
	static int[] dc = { 0, 0, -1, 1 };

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		visited = new boolean[N][N];
		map1 = new char[N][N];
		map2 = new char[N][N];
		
		// 초기화
		for (int i = 0; i < N; i++) {
			char[] input = br.readLine().toCharArray();
			for (int j = 0; j < N; j++) {
				map1[i][j] = input[j];
				if (input[j] == 'R' || input[j] == 'G')
					map2[i][j] = 'S';
				else 
					map2[i][j] = 'B';
			}
		}

		// 적록색약이 아닌 사람
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					cnt++;
					dfs(i, j, map1, 1);
				}
			}
		}

		// 적록색약인 사람
		for(boolean[] visit : visited) {
			Arrays.fill(visit, false);
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j])
					rgb++;
					dfs(i, j, map2, 2);
			}
		}

		System.out.print(cnt + " " + rgb);
	}

	static void dfs(int row, int col, char[][] map, int n) {
		visited[row][col] = true;

		for (int i = 0; i < 4; i++) {
			int nr = row + dr[i];
			int nc = col + dc[i];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc])
				continue;

			if (map[row][col] != map[nr][nc]) {
				continue;
			}
			dfs(nr, nc, map, n);
		}
	}
}
