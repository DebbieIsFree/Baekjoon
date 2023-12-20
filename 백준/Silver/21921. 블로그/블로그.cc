#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    
    int N, X;
    cin >> N >> X;
    
    vector<int> v(N+1, 0);
    vector<int> arr(N+1, 0);
    
    for(int i=1; i<=N; i++){
        cin >> v[i];
    }
    
    for(int i=1; i<=N; i++){
        arr[i] = arr[i-1] + v[i];
    }
    
    int left = 0, right = 0;
    int m = 0;
    
    map<int, int> mp;
    
    while(left<=right && (left<=N && right<=N)){
        if(right - left != X){
            right++;
        }
        else{
            int n = arr[right]-arr[left];
            if(mp.find(n) != mp.end()){
                mp[n] += 1;
            }else{
                mp.insert({n, 1});
            }
            
            if(m < n){
                m = n;
            }
            left++;
            right++;
        }
    }
    
    if(!m){
        cout << "SAD";
    }
    else{
        cout << m << "\n" << mp[m];
    }
    
    return 0;
}


