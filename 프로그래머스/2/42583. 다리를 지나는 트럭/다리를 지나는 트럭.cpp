#include <string>
#include <vector>
#include <queue>
using namespace std;

int answer = 0;
queue<int> trucks;          // {truck_weights}
queue<pair<int,int>> q;     // {time, truck_weights}

int solution(int bridge_length, int limit_weight, vector<int> truck_weights) {
    
    for(int i=0; i<truck_weights.size(); i++){
        trucks.push({truck_weights[i]});
    }
    
    int cnt = 0;
    int w = 0;
    
    while(true){
        cnt++;
        
        if(!trucks.empty() && (w + trucks.front() <= limit_weight)){
            q.push({bridge_length, trucks.front()});
            w += trucks.front();
            trucks.pop();
        }
        
        if(q.empty())
            break;
        
        // 이렇게 안 하고 for문에서 바로 i<q.size() 하면,
        // q.pop() 연산으로 q의 사이즈가 동적으로 변하는 것을 반영해서
        // 예를 들어,원래라면 2번 수행해야 할 것을 1번만 수행하고 끝나게 된다.
        int n = q.size();
        
        for(int i=0; i<n; i++){
            int tm = q.front().first;
            int truck_w = q.front().second;
            q.pop();
            
            if(tm-1 > 0){
                q.push({tm-1, truck_w});  
            }else if(tm-1 == 0){
                w -= truck_w;
            }
        }
    }
    
    answer = cnt;
    
    return answer;
}