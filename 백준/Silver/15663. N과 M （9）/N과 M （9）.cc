#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int N, M;
vector<int> v;
int selected[8];
bool isVisited[8];
set<string> s;

void perm(int tgtIdx){
    if(tgtIdx == M){
        string str = "";
        for(int i=0; i<M; i++){
            str += to_string(selected[i]);
            str += " ";
        }
        str += "\n";
        if(s.find(str) == s.end()){
            s.insert(str);
            cout << str;
        }
        return;
    }
    
    for(int i=0; i<N; i++){
        if(isVisited[i])
            continue;
        
        isVisited[i] = true;
        selected[tgtIdx] = v[i];
        perm(tgtIdx+1);
        isVisited[i] = false;
    }
}

int main(){
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        int n;  cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());
    
    perm(0);

    return 0;
}