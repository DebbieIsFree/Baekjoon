#include <iostream>
#include <map>
using namespace std;


int main(){
    
    int A, B;
    cin >> A >> B;
    
    map<int, int> m;
    
    while(A--){
        int n;  cin >> n;
        if(m.find(n) == m.end()){
            m.insert({n, 1});   
        }else{
            m[n] += 1;
        }
    }
    
    while(B--){
        int n;  cin >> n;
        if(m.find(n) == m.end()){
             m.insert({n, 1});   
        }else{
            m[n] += 1;
        }
    }
    
    int answer = 0;
    
    for (auto iter : m) {
        if(iter.second <= 1){
            answer++;
        }
    }
    
    cout << answer;

    return 0;
}


