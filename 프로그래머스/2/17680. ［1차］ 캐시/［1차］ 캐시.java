import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        int ans = 0;
        
        Set<String> s = new LinkedHashSet<>();
        
        for(int i=0; i<cities.length; i++){
            if(s.contains(cities[i].toUpperCase())){
                s.remove(cities[i].toUpperCase());
                s.add(cities[i].toUpperCase());
                ans += 1;
            }
            else {
                s.add(cities[i].toUpperCase());
                ans += 5;
                
                if(s.size() > cacheSize){
                    Iterator<String> iter = s.iterator();
                    String tmp = iter.next();
                    s.remove(tmp);
                }
            }
        }
        
        return ans;
    }
}