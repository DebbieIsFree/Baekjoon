#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int N, M;
int selected[8];
vector<int> v;
set<string> s;

void func(int tgtIdx, int startIdx){
    if(tgtIdx == M){
        string tmp = "";
        for(int i=0; i<M; i++){
            tmp += to_string(selected[i]) + " ";
        }
        if(s.find(tmp) == s.end()){
            cout << tmp << "\n";
            s.insert(tmp);
        }
        return;
    }
    
    for(int i=startIdx; i<N; i++){
        selected[tgtIdx] = v[i];
        func(tgtIdx+1, i);
    }
}

int main(){
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        int n;  cin >> n;
        v.push_back(n);
    }
    
    sort(v.begin(), v.end());
    
    func(0, 0);
    
    return 0;
}