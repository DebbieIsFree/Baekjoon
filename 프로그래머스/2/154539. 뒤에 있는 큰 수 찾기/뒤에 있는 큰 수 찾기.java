import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        int sz = numbers.length;
        Deque<Integer> st = new ArrayDeque<>();
        int[] answer = new int[sz];
        
        for(int i=sz-1; i>=0; i--){
            if(st.isEmpty()){
                answer[i] = -1;
                st.push(numbers[i]);
            }else{
                if(st.peek() > numbers[i]){
                    answer[i] = st.peek();
                    st.push(numbers[i]);
                }else{
                    while(!st.isEmpty() && st.peek() <= numbers[i]){
                        st.pop();
                    }
                    if(st.isEmpty())
                        answer[i] = -1;    
                    else
                        answer[i] = st.peek();    
                    st.push(numbers[i]);
                }
            }
        }
        
        return answer;
    }
}