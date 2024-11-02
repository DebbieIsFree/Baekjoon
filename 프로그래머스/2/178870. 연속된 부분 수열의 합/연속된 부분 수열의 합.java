class Solution {
    
    public int[] solution(int[] sequence, int k) {
        int ansLeft = 0;
        int ansRight = 987654321;
        
        int len = sequence.length;
        int left = 0;
        int right = 0;
        long sum = sequence[0];
        
        while(right < len && left <= right){
            if(sum == k){
                if(ansRight-ansLeft > right-left){
                    ansRight = right;
                    ansLeft = left;
                }
                else if((ansRight-ansLeft == right-left) && ansLeft > left){
                    ansRight = right;
                    ansLeft = left;
                }
            }
            
            if(sum <= k){
                if(right + 1 == len)
                    break;
                right++;
                sum += sequence[right];
            }else if(sum > k){
                sum -= sequence[left];
                left++;  
            }
        }
        
        int[] answer = {ansLeft, ansRight};
                
        return answer;
    }
}