import java.util.*;

public class Solution{
    
    static HashMap<Integer, Node> list = new HashMap<>();
    static TreeMap<Integer, Integer> timeList = new TreeMap<>();
    
	public int[] solution(int[] fees, String[] records) {
        
	    int len = records.length;
	    
	    for(int i=0; i<len; i++){
	        String[] parsedStr = records[i].split(" ");
	        
	        String cmd = parsedStr[2];      
	        int carNum = Integer.parseInt(parsedStr[1]);
	        String[] time = parsedStr[0].split(":");
	        
	        int hour = Integer.parseInt(time[0]);
	        int min = Integer.parseInt(time[1]);
	        
	        if(cmd.equals("IN")){
	            list.put(carNum, new Node(hour, min));
	        }else{
	            Node node = list.get(carNum);
	            list.remove(carNum);
	            
	            int inHour = node.inHour;
	            int inMin = node.inMin;
	            
	            accumulateTime(carNum, inHour, inMin, hour, min);
	        }
	    }
	    
	    for(int carNum : list.keySet()){
	        Node node = list.get(carNum);
	        // list.remove(carNum);
	        
	        int inHour = node.inHour;
            int inMin = node.inMin;
            
            accumulateTime(carNum, inHour, inMin, 23, 59);
	    }
	    
	    int[] answer = new int[timeList.size()];
	    int idx = 0;
	    
	    for(int carNum : timeList.keySet()){
	        int fee = calc(carNum, fees);
	        answer[idx++] = fee;
	    }
        
        return answer;
	}
	
	public void accumulateTime(int carNum, int inHour, int inMin, int outHour, int outMin){
	    int totalMin = 0;
	    
	    if(inHour == outHour){
            totalMin += (outMin - inMin);
        }else{
            outHour -= 1;
            totalMin += (60 - inMin) + outMin;
            if(outHour - inHour > 0)
                totalMin += (outHour - inHour) * 60;
        }
	    
	    if(timeList.containsKey(carNum)){
	        int val = timeList.get(carNum);
	        timeList.put(carNum, val + totalMin);
	    }else{
	        timeList.put(carNum, totalMin);   
	    }
	}
	
	public int calc(int carNum, int[] fees){
	    int totalMin = timeList.get(carNum);
	    
	    if(totalMin <= fees[0])
	        return fees[1];
	   
	    // 기본 시간 초과
        int res = fees[1];
	    totalMin -= fees[0];
	    
	    res += (totalMin / fees[2]) * fees[3];
	    totalMin %= fees[2];
	    
	    if(totalMin != 0)
	        res += fees[3];
	   
	    return res;
	}
	
	public class Node{
	    int inHour;
	    int inMin;
	    
	    public Node(int h, int m){
	        this.inHour = h;
	        this.inMin = m;
	    }
	}
}