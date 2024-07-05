#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> answer;
map<string, int> findID;                // {genre, id}
// vector<int> totalCnt(100);
map<int, int> totalCnt;                 // {genre, totalCnt};
vector<vector<pair<int,int>>> v(100);   // {cnt, uniqueId} 

bool comp(pair<int,int> o1, pair<int,int> o2){
    if(o1.first != o2.first)
        return o1.first > o2.first;
    return o1.second < o2.second;
}

bool comp2(pair<int,int> o1, pair<int,int> o2){
    if(o1.second == o2.second)
        return o1.first < o2.first;
    return o1.second > o2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    int sz = genres.size();
    int n = 0;
    int idx = 0;
    
    for(int i=0; i<sz; i++){
        string genre = genres[i];
        int cnt = plays[i];
        
        int index = 0;
        
        if(findID.find(genre) == findID.end()){
            findID.insert({genre, idx});
            index = idx;
            idx++;
            n++;
        }else{
            index = findID[genre];
        }
        // totalCnt[index] += cnt;
        totalCnt[index] += cnt;
        v[index].push_back({cnt, i});
    }
    
    // sort(totalCnt.begin(), totalCnt.end(), greater<int>());
    vector<pair<int,int>> tc(totalCnt.begin(), totalCnt.end());
    sort(tc.begin(), tc.end(), comp2);
    
    for(int i=0; i<n; i++){
        sort(v[i].begin(), v[i].end(), comp);
    }
    
    for(int i=0; i<n; i++){
        int idx = tc[i].first;
        
        int N = 2;
        if(v[idx].size() < 2)
            N = v[idx].size();
        
        for(int j=0; j<N; j++){
            answer.push_back(v[idx][j].second);
        }
    }
    
    return answer;
}