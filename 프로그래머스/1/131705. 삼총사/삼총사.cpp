#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    bool visited[13] = {0,};
    int len = number.size();
    
    
    for(int i=0; i<=len-3; i++){
        for(int j=i+1; j<=len-2; j++){ 
            for(int k=j+1; k<=len-1; k++){    
                int tmp = number[i] + number[j] +number[k];
                
                if(tmp == 0)
                    answer++;
            }
        }
    }
    

    return answer;
}