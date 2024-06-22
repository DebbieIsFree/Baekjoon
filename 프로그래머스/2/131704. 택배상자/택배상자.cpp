#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> st;
    queue<int> q;
    
    int N = order.size();
    
    for(int i=1; i<=N; i++){
        q.push(i);
    }
    
    int idx = 0;
    
    while(idx < N){
        if(!q.empty() && q.front() == order[idx]){
            q.pop();
            idx++;
            answer++;
        }
        else if(!st.empty() && st.top() == order[idx]){
            st.pop();
            idx++;
            answer++;
        }
        else if(!q.empty() && q.front() != order[idx]){
            st.push(q.front());
            q.pop();
        }
        else{
            break;
        }
    }
    
    return answer;
}