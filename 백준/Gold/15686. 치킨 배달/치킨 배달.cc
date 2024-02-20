#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

int N, M;
vector<pair<int,int>> home;
vector<pair<int, int>> chicken;
set<set<int>> s;

int selected[13];
vector<int> dist(50, 987654321);  // 각 home마다 최소 치킨 거리 저장
int sum = 987654321;

void calculate(set<int> s){
    vector<int> tmpDist(home.size(), 987654321);
    
    for(int num : s){
        int chIdx = num;  // 선택된 치킨집 번호(index)
            
        int chr = chicken[chIdx].first; //  각 치킨집 좌표
        int chc = chicken[chIdx].second;    
        for(int j=0; j<home.size(); j++){
            int hr = home[j].first;
            int hc = home[j].second;
            int dst = abs(chr-hr) + abs(chc - hc);
            if(dst < tmpDist[j])
                tmpDist[j] = dst;
        }
    }

    int tmp = 0;
    for(int distance : tmpDist){
        tmp += distance;
    }
        
    if(tmp < sum)
        sum = tmp;
}

void comb(int srcIdx, int tgtIdx){
    if(tgtIdx == M){
        set<int> tmpSet;
        for(int i=0; i<M; i++){
            tmpSet.insert(selected[i]);
        }
        if(s.find(tmpSet) == s.end()){
            s.insert(tmpSet);
            calculate(tmpSet);
        }    
        return;
    }
    
    if(srcIdx == chicken.size())
        return;
        
    
    for(int i=srcIdx; i<chicken.size(); i++){
        selected[tgtIdx] = i;
        comb(i+1, tgtIdx+1);
        comb(i+1, tgtIdx);
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(nullptr);
        
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int n;  cin >> n;
            if(n == 1){
                home.push_back({i+1, j+1});
            }else if(n == 2){
                chicken.push_back({i+1, j+1});
            }
        }
    }

    comb(0, 0);
    
    cout << sum;
    
    return 0;
}


