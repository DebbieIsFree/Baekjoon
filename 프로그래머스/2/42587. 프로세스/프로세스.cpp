#include <string>
#include <vector>
#include <queue>
using namespace std;

int answer = 0;
queue<pair<int,int>> q;         // {우선순위, index}
priority_queue<int> pq;

int solution(vector<int> priorities, int location) {
    int n = priorities.size();
    
    for(int i=0; i<n; i++){
        int pr = priorities[i];
        q.push({pr, i});
        pq.push(pr);
    }
    
    int cnt = 0;
    
    while(!q.empty()){
        int q_pr = q.front().first;
        int idx = q.front().second;
        q.pop();
        
        int pq_pr = pq.top();
        
        if(q_pr == pq_pr){
            pq.pop();
            cnt++;
        
            if(idx == location){
                answer = cnt;
                break;
            }
        }else{
            q.push({q_pr, idx});
        }
    }
    
    return answer;
}