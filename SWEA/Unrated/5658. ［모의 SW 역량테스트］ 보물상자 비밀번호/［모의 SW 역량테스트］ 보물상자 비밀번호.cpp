
#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// swea 5658

int main(){
    int T;  cin >> T;
    
    for(int tc=1; tc<=T; tc++){
        int N, K;
        cin >> N >> K;
        
        char arr[28];
        set<string> s;
        
        string str; cin >> str;
        
        for(int i=0; i<N; i++){
            arr[i] = str[i];
        }
        
        
        int sz = N / 4;
        
        for(int r=0; r<sz; r++){
            // 집어넣기
            string stmp = "";
            int sameCnt = 0;
            
            for(int i=0; i<N; i++){
                stmp += arr[i];
                
                if(i % sz == sz-1){
                    if(s.find(stmp) == s.end()){
                        s.insert(stmp);
                        stmp = "";
                    }
                }
            }
            
            
            
            // 회전
            int tmp[28];
            copy(arr, arr + N, tmp);
            for(int i=0; i<N; i++){
                arr[(i+1)% N] = tmp[i]; 
            }
        }
        
        vector<int> v;
        
        for(auto e : s){
            int n = stoi(e, nullptr, 16);
            v.push_back(n);
        }
        
        sort(v.begin(), v.end(), greater<int>());
        
        cout << "#" << tc << " " << v[K-1] << "\n";
    }
    return 0;
}