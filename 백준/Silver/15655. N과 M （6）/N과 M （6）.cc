#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> num;
bool visited[8];
int arr[9];

void func(int cnt, int cur_num){
    if(cnt+1 == M){
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<N; i++){
        if(cur_num >= num[i])
            continue;
        
        if(!visited[i]){
            visited[i] = true;
            arr[cnt + 1] = num[i];
            func(cnt + 1, num[i]);
            visited[i] = false; 
            
        }
    }
}


int main(){
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        int n;  cin >> n;
        num.push_back(n);
    }
    
    sort(num.begin(), num.end());
    
    for(int i=0; i<N; i++){
        visited[i] = true;
        arr[0] = num[i];
        func(0, num[i]);
        visited[i] = false; 
        
    }
    
    return 0;
}

