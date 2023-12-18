#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool func(pair<pair<int, int>, string>& o1, pair<pair<int, int>, string>& o2){
    if(o1.first.first == o2.first.first){
        return o1.first.second < o2.first.second;
    }
    else{
        return o1.first.first < o2.first.first;
    }
}

int main(){
    
    int N;  cin >> N;
    
    // age, idx, name
    vector<pair<pair<int, int>, string>> v;
    
    for(int i=0; i<N; i++){
        int age; 
        string name;
        cin >> age >> name;
        
        v.push_back(make_pair(make_pair(age, i), name));
    }
    
    sort(v.begin(), v.end(), func);
    
    for(int i=0; i<N; i++){
        cout << v[i].first.first << " " << v[i].second << "\n";
    }
    
    return 0;
}
