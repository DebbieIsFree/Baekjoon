import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int[] people;
	static int[][] matrix;
	static int[] selected = new int[10];
	static int ans = Integer.MAX_VALUE;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		matrix = new int[N + 1][N + 1];
		people = new int[N + 1];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) { // 각 정점의 인구수 저장
			people[i] = Integer.parseInt(st.nextToken());
		}

		for (int i = 1; i <= N; i++) {
			matrix[i][i] = 1;
		}

		for (int i = 1; i <= N; i++) { // 인접 리스트
			st = new StringTokenizer(br.readLine());
			int cnt = Integer.parseInt(st.nextToken());
			for (int j = 0; j < cnt; j++) {
				int node = Integer.parseInt(st.nextToken());
				matrix[i][node] = 1; // 인접 정점 넣기
				matrix[node][i] = 1; // 인접 정점 넣기f
			}
		}

		for (int i = 1; i <= N - 1; i++) {
			comb(1, 0, i);
		}

		if (ans == Integer.MAX_VALUE)
			System.out.println("-1");
		else
			System.out.println(ans);

	} // main

	static void comb(int srcIdx, int tgtIdx, int limit) {
		if (tgtIdx == limit) {
			List<Integer> listA = new ArrayList<>();
			List<Integer> listB = new ArrayList<>();
			int idx = 0;
			for(int i=1; i<=N; i++) {
				if(i == selected[idx]) {
					listA.add(i);
					idx++;
				}else {
					listB.add(i);
				}
			}
			int cost = check(listA, listB);
			ans = Math.min(ans, cost);
			return;
		}
		if (srcIdx == N + 1)
			return;

		selected[tgtIdx] = srcIdx;
		comb(srcIdx + 1, tgtIdx + 1, limit);
		comb(srcIdx + 1, tgtIdx, limit);
	}

	static boolean dfs(int start, boolean[] visited, List<Integer> list, int cnt) {
		visited[start] = true;

		if (cnt == list.size()) {
			return true;
		}

		for (int i = 1; i <= N; i++) {
			if (!visited[i] && matrix[start][i] == 1 && list.contains(i)) {
				dfs(i, visited, list, cnt + 1);
			}
		}
		
		for(int idx : list) {
			if(!visited[idx])
				return false;
		}
		return true;
	}

	static int check(List<Integer> listA, List<Integer> listB) {
		boolean[] visitedA = new boolean[N + 1];
		boolean[] visitedB = new boolean[N + 1];
		boolean successA = dfs(listA.get(0), visitedA, listA, 1);
		boolean successB = dfs(listB.get(0), visitedB, listB, 1);
		
		int costA = 0;
		int costB = 0;
		for (int a : listA) {
			costA += people[a];
		}
		for (int b : listB) {
			costB += people[b];
		}
		
		if (successA && successB) {
			return Math.abs(costA - costB);
		}

		return Integer.MAX_VALUE;
	}
}
