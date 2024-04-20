#include <iostream>
#include <queue>
#include <tuple>
#include <cstring> // memset
#include <climits>
using namespace std;

int n, a, b, da, db;

int func(int a, int b) {
    queue<tuple<int, int, int>> q;
    q.push({a, b, 0});

    bool visited[501][501]; 
    memset(visited, false, sizeof(visited));
    visited[a][b] = true;

    int answer = INT_MAX;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {    // 큐의 현재 크기만큼만 반복, 현재 큐에 들어있는 모든 원소에 대해 동일한 레벨의 처리 
            int ca, cb, cnt;
            tie(ca, cb, cnt) = q.front();
            q.pop();

            // cout << endl << "cnt : " << cnt;

            int nxt_a1 = ca + da;
            int nxt_a2 = ca - da;
            if(nxt_a1 > n) nxt_a1 %= n; 
            if (nxt_a2 <= 0) nxt_a2 += n; // 0일 때 n으로 조정
            cnt++;

            // cout << endl << nxt_a1 << ", " << nxt_a2;

            // 이후에 A지목권을 가질 후보 원소 중에, 현재 B지목권을 가진 원소와 같다면
            if (nxt_a1 == cb || nxt_a2 == cb) {
                answer = min(answer, cnt);
                continue;
            }

            int nxt_b1 = (cb + db) % n;
            int nxt_b2 = (cb - db + n) % n;
            if(nxt_b1 > n) nxt_b1 %= n;
            if (nxt_b2 <= 0) nxt_b2 += n; // 0일 때 n으로 조정
            cnt++;  
            
            // cout << endl << nxt_b1 << ", " << nxt_b2;

            // 이후후에 B지목권을 가진 후보 원소 중에, 이후에 A지목권을 가질 원소와 값이 같다면
            if (nxt_b1 == nxt_a1 || nxt_b1 == nxt_a2 || nxt_b2 == nxt_a1 || nxt_b2 == nxt_a2) {
                answer = min(answer, cnt);
                continue;
            }

            for (int nxt_a : {nxt_a1, nxt_a2}) {
                for (int nxt_b : {nxt_b1, nxt_b2}) {
                    if (!visited[nxt_a][nxt_b]) {
                        visited[nxt_a][nxt_b] = true;
                        q.push({nxt_a, nxt_b, cnt});
                    }
                }
            }
        }
    }

    return answer;
}

int main() {
    cin >> n >> a >> b >> da >> db;
    
    int ret = func(a, b);
    
    if(ret == INT_MAX)
        cout << "Evil Galazy";
    else 
        cout << ret;

    return 0;
}
