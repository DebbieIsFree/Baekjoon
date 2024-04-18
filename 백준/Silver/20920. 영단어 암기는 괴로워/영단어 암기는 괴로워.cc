#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<string,int> o1, pair<string,int> o2){
    if(o1.second == o2.second){
        if(o1.first.length() == o2.first.length()){
            return o1.first < o2.first;
        }else{
            return o1.first.length() > o2.first.length();
        }
    }else{
        return o1.second > o2.second;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    int N, M;
    cin >> N >> M;

    map<string, int> m;

    for(int i=0; i<N; i++){
        string str; cin >> str;
        
        if(str.length() < M)
            continue;
        
        m[str] += 1;
    }
    
    map<string, int>::iterator iter;
    vector<pair<string,int>> v;
    
    for(iter = m.begin(); iter != m.end(); iter++){
        v.push_back({(*iter).first, (*iter).second});
    }

    sort(v.begin(), v.end(), comp);

    for(int i=0; i<v.size(); i++){
        cout << v[i].first << "\n";
    }
    
    return 0;
}

