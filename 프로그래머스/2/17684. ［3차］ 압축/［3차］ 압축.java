import java.io.*;
import java.util.*;

class Solution {
    
    static HashMap<String, Integer> hm = new HashMap<>();
    static Queue<Integer> q = new ArrayDeque<>();
    
    public int[] solution(String msg) {
        int size = 26;
        
        for(int i=0; i<26; i++){
            hm.put(String.valueOf((char)('A' + i)), i+1);
        }
        
        String str = "";
        
        for(int i=0; i<msg.length(); ){
            StringBuilder tmp = new StringBuilder();

            while(i < msg.length()){
                tmp.append(msg.charAt(i));
                
                if(hm.containsKey(tmp.toString())){
                    str = tmp.toString();
                    i++;
                }
                else{
                    q.add(hm.get(str));
                    size++;
                    hm.put(tmp.toString(), size);
                    break;
                }
            }
        }
        
        if(!str.equals("")){
             q.add(hm.get(str));
        }
       
        int sz = q.size();
        int answer[] = new int[sz];
        int idx = 0;
        
        while(!q.isEmpty()){
            answer[idx] = q.peek();
            q.remove();
            idx++;
        }
        
        return answer;
    }
}