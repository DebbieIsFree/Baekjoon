import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main{
    
    static Stack<Integer> plus = new Stack<>();
    static Stack<Integer> minus = new Stack<>();
    static Boolean flag = false;
    static String tmp = "";
    
	public static void main(String[] args) throws Exception{
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    String str = br.readLine();
	    
	    for(int i=0; i<str.length(); i++){
	        if(str.charAt(i) != '+' && str.charAt(i) != '-'){
	            tmp += str.charAt(i);
	        }else{
	            if(str.charAt(i) == '+' && !flag){
	                plus.push(Integer.valueOf(tmp));
	                tmp = "";
	            }if(str.charAt(i) == '+' && flag){
	                minus.push(Integer.valueOf(tmp));
	                tmp = "";
	            }else if(str.charAt(i) == '-' && !flag){
	                plus.push(Integer.valueOf(tmp));
	                tmp = "";
	                flag = true;
	            }else if(str.charAt(i) == '-' && flag){
	                minus.push(Integer.valueOf(tmp));
	                tmp = "";
	            }
	        }
	    }
	    
	    if(flag){
	        minus.push(Integer.valueOf(tmp));
	    }else{
	        plus.push(Integer.valueOf(tmp));
	    }
	    
	    Integer pvalue = 0;
	    Integer mvalue = 0;
	    
	    while(!plus.isEmpty()){
	        pvalue += Integer.valueOf(plus.peek());
	        plus.pop();
	    }
	    
	    while(!minus.isEmpty()){
	        mvalue += Integer.valueOf(minus.peek());
	        minus.pop();
	    }
	    
	    System.out.print(pvalue-mvalue);
	}
}
