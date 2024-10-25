import java.util.*;

class Solution {
    static HashMap<String, Car> hm = new HashMap<>();
    static TreeMap<String, Integer> result = new TreeMap<>();
    
    public int[] solution(int[] fees, String[] records) {
        
        for(int i=0; i<records.length; i++){
            String[] tmp = records[i].split(" ");
            
            String carNum = tmp[1];
            String sign = tmp[2];
            
            String[] time = tmp[0].split(":");
            int hour = Integer.valueOf(time[0]);
            int min = Integer.valueOf(time[1]);
            
            if(sign.equals("IN")){
                hm.put(carNum, new Car(carNum, hour, min));
            }else{
                Car inCar = hm.get(carNum);
                hm.remove(carNum);    
                int inHour = inCar.hour;
                int inMin = inCar.min;
                accumulate(carNum, inHour, inMin, hour, min);
            }
        }
        
        for(String key : hm.keySet()){
            Car c = hm.get(key);
            String carNum = c.carNum;
            // hm.remove(carNum);
            
            int inHour = c.hour;
            int inMin = c.min;
            accumulate(carNum, inHour, inMin, 23, 59);
        }
        
        TreeMap<String, Integer> ans = new TreeMap<>();
        
        int[] answer = new int[result.size()];
        int idx = 0;
        
        for(String key : result.keySet()){
            int total = result.get(key);
            
            if(total <= fees[0]){
                ans.put(key, fees[1]);
            }else{
                total -= fees[0];
                int res = fees[1];
                
                res += total/fees[2]*fees[3];
                total = total % fees[2];
                if(total != 0){
                    res += fees[3];
                }
                ans.put(key, res);
            }
            answer[idx] = ans.get(key);
            idx++;
        }
        return answer;
    }
    
    public void accumulate(String carNum, int inHour, int inMin, int hour, int min){
        int sum = 0;

        if(inMin <= min){
            sum += (min - inMin);
            sum += (hour - inHour) * 60;
        }else{
            sum += (60 - inMin) + min;
            hour -= 1;
            sum += (hour - inHour) * 60;
        }
        if(result.containsKey(carNum)){
            int prevSum = result.get(carNum);
            result.put(carNum, prevSum + sum);
        }else{
            result.put(carNum, sum);
        }
    }
    
    public class Car{
        String carNum;
        int hour;
        int min;
        
        public Car(String carNum, int hour, int min){
            this.carNum = carNum;
            this.hour = hour;
            this.min = min;
        }
    }
}