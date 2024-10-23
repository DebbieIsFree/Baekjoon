import java.util.*;

class Solution {
    public int solution(int[] topping) {
        int answer = 0;
        
        HashMap<Integer, Integer> hm = new HashMap<>();
        
        for(int i=0; i<topping.length-1; i++){
            if(hm.containsKey(topping[i])){
                hm.put(topping[i], hm.get(topping[i]) + 1);
            }else{
                hm.put(topping[i], 1);
            }
        }
        
        int kind = hm.size();
        int len = topping.length;
        int left = len - 2;  
        int right = len - 1;
        
        HashSet<Integer> rightSet = new HashSet<>();
        rightSet.add(topping[right]);
        
        while(left >= 0 && left < right){
            if(kind == rightSet.size()){
                answer++;
            }
            
            if(kind >= rightSet.size()){
                int num = topping[left];
                int cnt = hm.get(num);
                
                if(cnt == 1){
                    hm.remove(num);
                    kind -= 1;
                }else{
                    hm.put(num, cnt-1);
                }
                rightSet.add(num);
                
                right = left;
                left -= 1;
            }else{
                break;
            }
        }
        
        
        return answer;
    }
}