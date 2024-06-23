#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

struct Node{
    int num, idx, res;
};

bool comp1(Node &o1, Node &o2){
    return o1.num < o2.num;
}

bool comp(Node &o1, Node &o2){
    return o1.idx < o2.idx;
}

int main(){
    cin >> N;
    
    vector<Node> v;
    
    for(int i=0; i<N; i++){
        int a;  cin >> a;
        v.push_back({a, i, 0});
    }
    
    // 그냥 sort(v.begin(), v.end()) 하면 에러 발생함
    sort(v.begin(), v.end(), comp1);
    
    int prev = v[0].num;
    int cnt = 0;
    
    for(int i=0; i<N; i++){
        if(prev < v[i].num){
            v[i].res = ++cnt;
        }
        if(prev == v[i].num){
            v[i].res = cnt;
        }
        prev = v[i].num;
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(int i=0; i<N; i++){
        cout << v[i].res << " ";
    }

    return 0;
}