import java.io.*;
import java.util.*;

class Solution {
    
    public int[] solution(String msg) {
        HashMap<String, Integer> map = new HashMap<>();
	    
	    for(int i=0; i<26; i++){
	        map.put(String.valueOf((char)('A'+i)), i+1);
	    }
	    
	    List<Integer> list = new ArrayList<>();
	    StringBuilder sb = new StringBuilder();
	    int idx = 0;
	    int cnt = 26;
	    
	    while(true){
	        if(idx == msg.length()){
	            int n = map.get(sb.toString());
	            list.add(n);
	            break;
	        }
	        
	        if( map.containsKey(sb.toString() + msg.charAt(idx)) ){
	            sb.append(msg.charAt(idx));
	        }else{
	            int n = map.get(sb.toString());
	            list.add(n);
	            map.put(sb.toString() + msg.charAt(idx), ++cnt);
	            sb = new StringBuilder();
	            sb.append(msg.charAt(idx));
	        }
	        idx++;
	    }
	    
	    
	    int answer[] = new int[list.size()];
	    for(int i=0; i<list.size(); i++){
	        answer[i] = list.get(i);
	    }
	    
	    return answer;
    }
}