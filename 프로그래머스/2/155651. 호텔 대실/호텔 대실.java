class Solution {
    public int solution(String[][] book) {
        int answer = 0;
        
        int arr[][] = new int[24][60];
        
        for(int i=0; i<book.length; i++){
            String[] str = book[i][0].split(":");
            int sH = Integer.valueOf(str[0]);
            int sM = Integer.valueOf(str[1]);
            
            str = book[i][1].split(":");
            int eH = Integer.valueOf(str[0]);
            int eM = Integer.valueOf(str[1]) + 9;
            
            if(eM >= 60){
                eH++;
                eM %= 60;
            }
            
            if(eH >= 24){
                eH = 23;
                eM = 59;
            }
            
            int h = sH;
            int m = sM;
            
            while(true){
                arr[h][m] += 1;
                answer = Math.max(answer, arr[h][m]);
                
                if(h == eH && m == eM)
                    break;
                else
                    m++;
                
                if(m == 60){
                    m = 0;
                    h++;
                }
            }
        }
        
        return answer;
    }
}