#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<double, int> o1, pair<double, int> o2){
    if(o1.first == o2.first) return o1.second < o2.second;
    return o1.first > o2.first;
}


vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, int> m;
    int people = stages.size();
    vector<pair<double, int>> tmp;
    
    for(auto st : stages){
        if(st == N+1){
            m.insert({st-1, 0});
            continue;
        }
        if(m.find(st) == m.end()){
            m.insert({st, 1});
        }
        else{
            m[st]++;
        }
    }
    
    for(int i=1; i<=N; i++){
        int pass = m[i];
        if(pass == 0 || people == 0){
            tmp.push_back({0, i});
        }else{
            tmp.push_back({(double)pass/people, i});    
        }    
        people -= pass;
    }
    
    sort(tmp.begin(), tmp.end(), comp);
    
   
    for(int i=0; i<tmp.size(); i++){
         answer.push_back(tmp[i].second);
    }
    
    return answer;
}




