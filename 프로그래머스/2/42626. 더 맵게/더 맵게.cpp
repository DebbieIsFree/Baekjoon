#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scv, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<scv.size(); i++){
        pq.push(scv[i]);
    }
    
    while(1){    
        if(pq.size() < 2 && pq.top() < K){
            answer = -1;
            break;
        }
        
        if(pq.size() < 2)
            break;
        
        int m1 = pq.top();
        pq.pop();
        int m2 = pq.top();
        pq.pop();
        
        if(m1 >= K && m2 >= K)
            break;
        
        if(m1 < K || m2 < K){
            answer++;
            int tmp = m1 + (m2 * 2);
            pq.push(tmp);
        }
    }
    return answer;
}


