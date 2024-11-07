import java.util.*;
import java.io.*;

public class Main{
    
    static int N;
    static int answer = 987_654_321;
    static int[] people;
    static boolean[][] map;
    static boolean[] selected;
    static boolean[] visited;
    static boolean flag;
    
	public static void main(String[] args) throws Exception{
	   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	   StringTokenizer st = new StringTokenizer(br.readLine());
	    
	   N = Integer.parseInt(st.nextToken());
	   people = new int[N+1];
	   map = new boolean[N+1][N+1];
	   selected = new boolean[N+1];
	   visited = new boolean[N+1];
	   
	   st = new StringTokenizer(br.readLine());
	   for(int i=1; i<=N; i++){
	       people[i] = Integer.parseInt(st.nextToken());
	   }
	   
	   for(int i=1; i<=N; i++){
	       st = new StringTokenizer(br.readLine());
	       int n = Integer.parseInt(st.nextToken());
	       
	       for(int j=1; j<=n; j++){
	           int adjIdx = Integer.parseInt(st.nextToken());
	           map[i][adjIdx] = true;
	       }
	   }
	   
	   for(int i=1; i<=N/2; i++){
	       comb(i, 0, 1);
	   }
	   
	   if(answer == 987_654_321)
	       System.out.println("-1");
	   else
	       System.out.println(answer);
	}
	
	public static void comb(int goal, int cnt, int start){
	    if(cnt == goal){
	        List<Integer> group1 = new ArrayList<>();
    	    List<Integer> group2 = new ArrayList<>();
    	    
    	    for(int i=1; i<=N; i++){
    	        if(selected[i])
    	            group1.add(i);
    	        else
    	            group2.add(i);
    	    }
    	   
	        boolean connected = isConnected(group1, group2);
	        if(connected){
	            calc(group1, group2);
	        }
	        return;
	    }
	    
	    for(int i=start; i<=N; i++){
	        if(selected[i])
	            continue;
	        
	        selected[i] = true;
	        comb(goal, cnt+1, i+1);
	        
	        selected[i] = false;
	        comb(goal, cnt, i+1);
	    }
	}
	
	public static boolean isConnected(List<Integer> group1, List<Integer> group2){
	    flag = false;
	    Arrays.fill(visited, false);
	    visited[group1.get(0)] = true;
	    dfs(group1.get(0), group1.size(), 1, group1);
	    if(!flag)
	        return false;
	    
	    flag = false;
        Arrays.fill(visited, false);	    
        visited[group2.get(0)] = true;
	    dfs(group2.get(0), group2.size(), 1, group2);
	    
	    if(!flag)
	        return false;
	        
	    return true;
	}
	
	public static int dfs(int start, int goal, int cnt, List<Integer> group){
	    int tmp = cnt;
	    
	    if(cnt == goal){
	        flag = true;
	        return tmp;
	    }
	    
	    for(int i=0; i<group.size(); i++){
	        int next = group.get(i);
	        
	        if(visited[next])
	            continue;
	       
	        if(!map[start][next])
	            continue;
	            
	    
	        visited[next] = true;
	        tmp = Math.max(tmp, dfs(next, goal, tmp+1, group));
	    }
	    return tmp;
	}
	
	public static void calc(List<Integer> group1, List<Integer> group2){
    	int sum1 = 0;
    	int sum2 = 0;
    	
    	for(int i=0; i<group1.size(); i++){
    	    int idx = group1.get(i);
    	    sum1 += people[idx];
    	}
    	
    	for(int i=0; i<group2.size(); i++){
    	    int idx = group2.get(i);
    	    sum2 += people[idx];
    	}
    	
    	answer = Math.min(answer, Math.abs(sum1 - sum2));
	}
}
