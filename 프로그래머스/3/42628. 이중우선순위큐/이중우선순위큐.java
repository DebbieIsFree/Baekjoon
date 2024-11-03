import java.util.*;

class Solution {
    public int[] solution(String[] op) {
        
        TreeMap<Integer, Integer> map = new TreeMap<>();
        
        for(int i=0; i<op.length; i++){
            String[] str = op[i].split(" ");
            String cmd = str[0];
            int n = Integer.parseInt(str[1]);
            
            if(cmd.equals("I")){
                if(map.containsKey(n)){
                    int tmp = map.get(n);
                    map.put(n, tmp+1);
                }else{
                    map.put(n, 1);
                }
            }else{
                if(map.isEmpty())
                    continue;
                
                int key = -1;
                int tmp = 0;
                
                if(n == 1){
                    key = map.lastKey();
                    tmp = map.get(key);
                }else{
                    key = map.firstKey();
                    tmp = map.get(key);
                }
                
                if(tmp - 1 == 0){
                    map.remove(key);   
                }else{
                    map.put(key, tmp-1);
                }
            }
        }
        
        int[] answer;
        
        if(map.isEmpty()){
            answer = new int[]{0, 0};
        }else{
            answer = new int[]{map.lastKey(), map.firstKey()};
        }
        
        return answer;
    }
}