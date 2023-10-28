#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progress, vector<int> speeds) {
    vector<int> answer;

    queue<int> q;
    
    for(int i=0; i<progress.size(); i++){
        int n = 100 - progress[i];
        int day = n / speeds[i];
        if(n % speeds[i] != 0)
            day += 1;
        q.push(day);
    }
    
    
    int cnt = 1;
    int limit = q.front();
    q.pop();
    
    while(!q.empty()){
        if(q.front() <= limit){
            cnt++;
            q.pop();
        }
        else{
            answer.push_back(cnt);
            cnt = 1;
            limit = q.front();
            q.pop();
        }
    }
    
    if(cnt > 0){
        answer.push_back(cnt);
    }
    
    return answer;
}


