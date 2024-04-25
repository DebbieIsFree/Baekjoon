#include <iostream>
#include <queue>
#include <map>
using namespace std;

// ex) 2 --> 6
// 2 --> 3 --> 6
// 2 -> 3 -> 4 -> 5 -> 6
// visited[]
    // 중복 금지
    // ex) 2 --> 1 --> 2 --> 3

// 참고 : https://velog.io/@yoohoo030/%EB%B0%B1%EC%A4%8012851-%EC%88%A8%EB%B0%94%EA%BC%AD%EC%A7%88-2-C
// 일반적인 BFS문제에서는 큐에 push할 때 visited 배열을 true로 만들어준다
// 하지만 이 문제에서는 큐에서 pop할 때 visited 배열을 true로 만들어줘야 한다. 왜냐하면 최단 경로의 '개수'를 알아내야 하기 때문에, 
// 특정 지점을 이미 한 번 방문했더라도 그 지점을 다시 방문할 수 있는 가능성을 열어둬야 하는 것

struct Node{
    int cur, t;
};

int min_time = 1e6;
map<int, int> m;
bool visited[100001];

int main(){
    int N, K;
    cin >> N >> K;
    
    queue<Node> q;
    q.push({N, 0});
    
    while(!q.empty()){
        int cur = q.front().cur;
        int ct = q.front().t;
        q.pop();
        
        visited[cur] = true;
        
        if(cur == K){
            m[ct] += 1;
            if(ct < min_time){
                min_time = ct;
            }
        }
        
        if(ct >= min_time)
            continue;
        
        if(cur - 1 >= 0 && !visited[cur-1]){
            // visited[cur-1] = true;
            q.push({cur-1, ct+1});
        }
        if(cur + 1 <= 100000 && !visited[cur+1]){
            // visited[cur+1] = true;
            q.push({cur+1, ct+1});
        }
        if(cur * 2 <= 100000 && !visited[cur*2]){
            // visited[cur*2] = true;
            q.push({cur*2, ct+1});
        }
    }
    
    
    cout << min_time << "\n";
    cout << m[min_time];

    return 0;
}
