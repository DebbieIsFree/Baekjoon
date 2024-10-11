#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
  int x, y;  
};


bool comp(Node &n1, Node &n2){
    if(n1.x != n2.x)
        return n1.x < n2.x;
    return n1.y < n2.y;
}


int main(){
    int N;  cin >> N;
    int x, y;
    
    vector<Node> v;
    
    while(N--){
        cin >> x >> y;
        
        v.push_back({x, y});
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(auto e : v){
        cout << e.x << " " << e.y << "\n";
    }

    return 0;
}