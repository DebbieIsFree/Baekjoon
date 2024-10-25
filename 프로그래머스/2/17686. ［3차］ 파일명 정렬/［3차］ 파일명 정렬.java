import java.util.*;

class Solution {
    public String[] solution(String[] files) {
        
        List<Node> list = new LinkedList<>();
        
        for(int i=0; i<files.length; i++){
            String file = files[i];
            String tmp = "";
            
            boolean numberFlag = false;
            
            String head = "";
            int number = -1;
            
            for(int j=0; j<file.length(); j++){
                if(!numberFlag && !Character.isDigit(file.charAt(j))){
                    tmp += file.charAt(j);
                }
                else if(!numberFlag && Character.isDigit(file.charAt(j))){
                    numberFlag = true;
                    head = tmp;
                    tmp = "";
                    tmp += file.charAt(j);
                }
                else if(numberFlag && Character.isDigit(file.charAt(j))){
                    tmp += file.charAt(j);
                }else{
                    number = Integer.valueOf(tmp);
                    tmp = "";
                    break;
                }
            }
            if(!tmp.equals("")){
                number = Integer.valueOf(tmp);
            }
            
            list.add(new Node(file, head.toUpperCase(), number, i));
        }
        
        list.sort(
                 Comparator.comparing(Node::getHead)
                 .thenComparing(Node::getNumber)
                 .thenComparing(Node::getIdx)
        );
        
        String[] answer = new String[list.size()];
        
        for(int i=0; i<list.size(); i++){
            answer[i] = list.get(i).fileName;
        }
        
        return answer;
    }
    
    public class Node{
        String fileName;
        String head;
        int number;
        int idx;
        
        public Node(String fn, String h, int n, int i){
            this.fileName = fn;
            this.head = h;
            this.number = n;
            this.idx = i;
        }
        
        public String getHead(){
            return head;
        }
        
        public int getNumber(){
            return number;
        }
        
        public int getIdx(){
            return idx;
        }
    }
}