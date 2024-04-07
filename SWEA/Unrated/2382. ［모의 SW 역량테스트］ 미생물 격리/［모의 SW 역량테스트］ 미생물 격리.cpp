#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <map>
using namespace std;

int N, M, K;

// (상: 1, 하: 2, 좌: 3, 우: 4)
int dr[] = {0, -1, 1, 0, 0};
int dc[] = {0, 0, 0, -1, 1};

struct Node {
    int row, col, cnt, maxCnt, dir;
};

int main() {
    int T;  
    cin >> T;
    
    for(int tc = 1; tc <= T; tc++) {
        cin >> N >> M >> K;
        
        queue<Node> q;
        map<pair<int, int>, Node> m;
        
        // 초기 미생물 군집 입력
        for(int i = 0; i < K; i++) {
            int row, col, cnt, dir;
            cin >> row >> col >> cnt >> dir;
            
            q.push({row, col, cnt, cnt, dir});
            m[{row, col}] = {row, col, cnt, cnt, dir};
        }
        
        while(M--) {
            map<pair<int, int>, Node> temp;
            
            while(!q.empty()) {
                Node node = q.front();
                q.pop();
                
                int cr = node.row;
                int cc = node.col;
                int cnt = node.cnt;
                int maxCnt = node.maxCnt;
                int dir = node.dir;
                
                int nr = cr + dr[dir];
                int nc = cc + dc[dir];
                
                // 이동하려는 곳이 경계(소독약 뿌려진 곳)
                if(nr == 0 || nr == N-1 || nc == 0 || nc == N-1) {
                    cnt /= 2;
                    if(dir % 2 == 1)    
                        dir += 1;
                    else 
                        dir -= 1;
                }
                
                if(cnt == 0)
                    continue;
                
                if(temp.find({nr, nc}) == temp.end()) {
                    temp[{nr, nc}] = {nr, nc, cnt, cnt, dir};
                } else {
                    Node& existing = temp[{nr, nc}];
                    existing.cnt += cnt;
                    if(existing.maxCnt < cnt){
                        existing.maxCnt = cnt;
                        existing.dir = dir;
                    }
                }
            }
            
            // temp의 값을 m으로 업데이트
            m.clear();
            m = temp;
            
            // 큐 다시 채워주기
            for(auto& kv : m) {
                q.push(kv.second);
            }
        }
        
        int sum = 0;
        for(auto& kv : m) {
            sum += kv.second.cnt;
        }
        
        cout << "#" << tc << " " << sum << "\n";    
    }

    return 0;
}
