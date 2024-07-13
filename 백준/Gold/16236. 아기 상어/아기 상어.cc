#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#define INF 987654321
using namespace std;

int N;
int arr[20][20];
int sr, sc;         // 아기 상어 위치
int sz = 2; 
int eat = 0;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool visited[20][20];

struct Node{
  int row, col, size, dist;  
};

vector<Node> v;

bool comp2(Node &n1, Node &n2){
    if(n1.dist != n2.dist){
        return n1.dist < n2.dist;
    }else{
        if(n1.row != n2.row){
            return n1.row < n2.row;
        }else{
            if(n1.col != n2.col){
                return n1.col < n2.col;
            }else{
                return n1.size < n2.size;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            
            if(1 <= arr[i][j] && arr[i][j] <= 6){
                v.push_back({i, j, arr[i][j], INF});      // 일단 임시로 아기상어와의 거리는 INF이라 둔다.
            }
            else if(arr[i][j] == 9){
                // 맨 처음에 아기상어가 있는 위치의 값을 0으로 초기화 해야
                // 나중에 아기상어의 크기(sz)보다 작은 위치인지 확인하고 지나갈 수 있다.
                // 0으로 초기화 안 하면, 맵에서 제일 큰 값이므로 지나갈 수 있음에도
                // 조건문에 걸려 지나갈 수 없음 처리가 된다.
                arr[i][j] = 0; 
                sr = i;
                sc = j;
            }
        }
    }
    
    int cnt = 0;
    
    while(true){
        // 현재 아기상어와 가장 가까운 물고기의 위치 구하기
        int n = v.size();
        
        for(int i=0; i<n; i++){
            int cr = v[i].row;
            int cc = v[i].col;
            int dst = abs(cr-sr) + abs(cc-sc);
            v[i].dist = dst;
        }
        
        // 정렬 (1. 거리, 2. 위치, 3. 크기 순으로..)
        sort(v.begin(), v.end(), comp2);
        
        bool flag = false;
        int ansIdx = -1;
        int movingCnt = 987654321;
        int ansNr = 0;
        int ansNc = 0;
        
        for(int idx=0; idx<n; idx++){
            if(v[idx].size >= sz)
                continue;
            
            int dst = (*(v.begin()+idx)).dist;
            int nr = (*(v.begin()+idx)).row;
            int nc = (*(v.begin()+idx)).col;
            
            queue<pair<pair<int,int>, int>> q;
            fill(&visited[0][0], &visited[0][0] + 20*20, false);
            q.push({{sr, sc}, 0});
            visited[sr][sc] = true;
            
            while(!q.empty()){
                int cr = q.front().first.first;
                int cc = q.front().first.second;
                int tmpCnt = q.front().second;
                q.pop();
                
                if(cr == nr && cc == nc){
                    // cout << endl << nr << ", " << nc;
                    
                    flag = true;
                    if(movingCnt > tmpCnt){
                        movingCnt = tmpCnt;
                        ansIdx = idx;
                        ansNr = cr;
                        ansNc = cc;
                    }
                    break;
                }
                
                for(int i=0; i<4; i++){
                    int tnr = cr + dr[i];
                    int tnc = cc + dc[i];
                    
                    if(tnr < 0 || tnr >= N || tnc < 0 || tnc >= N || visited[tnr][tnc] || arr[tnr][tnc] > sz)
                        continue;
                    
                    visited[tnr][tnc] = true;
                    q.push({{tnr, tnc}, tmpCnt+1});
                }
            }
        }
        
        if(ansIdx != -1){
            v.erase(v.begin() + ansIdx);
            eat++;
            sr = ansNr;
            sc = ansNc;
            arr[sr][sc] = 0;
            cnt += movingCnt;
        }
        
        if(ansIdx == -1){
            break;
        }
        
        if(eat == sz){
            sz += 1;
            eat = 0;
        }
    }
    
    cout << cnt;
    
    return 0;
}