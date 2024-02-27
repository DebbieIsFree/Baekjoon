import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

// 시작점에서 다른 모든 정점으로의 최단 경로 (1:N) --> 다익스트라 (양의 간선)

public class Main {

	static int V, E, K;
	static int[] minDistance;
	static PriorityQueue<Edge> pq = new PriorityQueue<>();
	static List<List<Edge>> adjList = new ArrayList<>();
	static boolean[] visited;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(br.readLine());
		
		minDistance = new int[V+1];	// 0 dummy
		visited = new boolean[V+1];
		
		Arrays.fill(minDistance, Integer.MAX_VALUE);
		
		for(int i=0; i<=V; i++) {
			adjList.add(new ArrayList<>());
		}
		
		for(int i=0; i<E; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			adjList.get(u).add(new Edge(v, w));
		}
		
		// 시작 정점
		minDistance[K] = 0;
		pq.offer(new Edge(K, 0));
		
		while(!pq.isEmpty()) {
			Edge cur = pq.poll();
			
			if(visited[cur.to])
				continue;
			visited[cur.to] = true;
			
			for(int i=0; i<adjList.get(cur.to).size(); i++) {
				int nextIdx = adjList.get(cur.to).get(i).to;
				int cost = adjList.get(cur.to).get(i).cost;
				
				if(cost + minDistance[cur.to] < minDistance[nextIdx]) {
					minDistance[nextIdx] = cost + minDistance[cur.to];
					pq.offer(new Edge(nextIdx, minDistance[nextIdx]));
				}
			}
		}
		
		for(int i=1; i<=V; i++) {
			if(minDistance[i] == Integer.MAX_VALUE)
				System.out.println("INF");
			else 
				System.out.println(minDistance[i]);
		}
		
	}// main

	static class Edge implements Comparable<Edge>{
		int to, cost;

		public Edge(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}

		@Override
		public int compareTo(Edge o) {
			return this.cost - o.cost;
		}
	}
	
}
