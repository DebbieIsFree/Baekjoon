#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    string left = "", right = "";
    
    for(int i=0; i<food.size(); i++){
        int n = food[i];
        
        while(n > 1){
            left += to_string(i);
            right = to_string(i) + right;
            n -= 2;
        }
    }
    
    answer = left + "0" + right;
    
    return answer;
}