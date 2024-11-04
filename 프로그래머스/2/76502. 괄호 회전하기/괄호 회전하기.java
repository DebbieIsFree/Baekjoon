import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        int len = s.length();
        
        for(int i=0; i<len; i++){
            Deque<Character> st = new ArrayDeque<>();
            int idx = i;
            
            for(int j=0; j<len; j++){
                st.push(s.charAt(idx));
                idx = (idx + 1) % len;
            }
            
            boolean flag = false;
            Deque<Character> tmp = new ArrayDeque<>();
            
            while(!st.isEmpty()){
                char ch = st.pop();
                
                if(ch == '}' || ch == ']' || ch == ')'){
                    tmp.push(ch);
                }else{
                    if(tmp.isEmpty()){
                        flag = true;
                        break;
                    }
                    char ch2 = tmp.pop();
                    
                    if(
                        !(ch == '(' && ch2 == ')')
                        && !(ch == '[' && ch2 == ']')
                        && !(ch == '{' && ch2 == '}')
                    ){
                        flag = true;
                        break;
                    }
                }
            }
            if(!flag && tmp.isEmpty())
                answer++;
        }
        return answer;
    }
}