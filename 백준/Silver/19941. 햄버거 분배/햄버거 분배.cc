#include <iostream>
#include <string>
using namespace std;

char table[20001];
bool isChecked[20001];

// greedy

int main(){
    int N, K;
    cin >> N >> K;
    
    string str; cin >> str;
    
    for(int i=0; i<str.length(); i++){
        table[i] = str[i];
    }
    
    int ans = 0;
    
    for(int i=0; i<N; i++){
        if(table[i] != 'P')
            continue;
        
        bool flag = false;
        
        // 범위 내 가장 왼쪽부터 먹을 수 있는 햄버거 찾기
        for(int left=K; left>=1; left--){
            int leftIdx = i-left;
        
            if(leftIdx >= 0 && table[leftIdx] == 'H' && !isChecked[leftIdx]){
                isChecked[leftIdx] = true;
                ans++;
                flag = true;
                break;
            }    
        }
        
        if(flag)
            continue;
        
        for(int right=1; right<=K; right++){
            int rightIdx = i+right;
            
            if(rightIdx < N && table[rightIdx] == 'H' && !isChecked[rightIdx]){
                isChecked[rightIdx] = true;
                ans++;
                break;
            }   
        }
    }

    cout << ans;

    return 0;
}