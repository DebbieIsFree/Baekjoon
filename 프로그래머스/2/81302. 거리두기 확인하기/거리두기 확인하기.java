import java.util.*;

class Solution {
    
    static int[] answer = new int[5];
    static char[][] map = new char[5][5];
    static boolean[][] visited = new boolean[5][5];
    static List<Person> list = new LinkedList<>();
    
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    static boolean flag = false;
    static int count = 0;
    
    public int[] solution(String[][] places) {
        
        for(int i=0; i<5; i++){
            String[] line = places[i];  // ["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"]
            list.clear();
            
            // each room (5*5)
            for(int j=0; j<5; j++){
                String row = line[j];   // "POOOP"
                
                for(int k=0; k<5; k++){
                    map[j][k] = row.charAt(k);
                    if(map[j][k] == 'P'){
                        list.add(new Person(j, k));
                    }
                }
            }
            answer[i] = func();
        }
        
        return answer;
    }
    
    public int func(){
        for(int i=0; i<list.size(); i++){
            Person p1 = list.get(i);
            
            for(int j=i+1; j<list.size(); j++){
                Person p2 = list.get(j);
                
                flag = false;
                count = 0;
                for(int k=0; k<5; k++){
                    Arrays.fill(visited[k], false);
                }
                
                bfs(p1.row, p1.col, p2.row, p2.col);
                
                if(flag && count <= 2)
                    return 0;
            }
        }
        return 1;
    }
    
    public void bfs(int cr, int cc, int gr, int gc){
        
        Queue<Node> q = new ArrayDeque<>();
        q.add(new Node(cr, cc, 0));
        visited[cr][cc] = true;
        
        while(!q.isEmpty()){
            Node node = q.poll();
            int r = node.row;
            int c = node.col;
            int cnt = node.cnt;
            
            if(r == gr && c == gc){
                flag = true;
                count = cnt;
                break;
            }
        
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nr >= 5 || nc < 0 || nc >= 5 || visited[nr][nc] || map[nr][nc] == 'X')
                    continue;
                
                visited[nr][nc] = true;
                q.add(new Node(nr, nc, cnt+1));
            }
        }
    }
    
    public class Person{
        int row;
        int col;
        
        public Person(int row, int col){
            this.row = row;
            this.col = col;
        }
    }
    
    public class Node{
        int row;
        int col;
        int cnt;
        
        public Node(int row, int col, int cnt){
            this.row = row;
            this.col = col;
            this.cnt = cnt;
        }
    }
}