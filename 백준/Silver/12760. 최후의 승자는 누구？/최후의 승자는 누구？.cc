#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int nums[100][100];
int ans[100];

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    int N, M;
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> nums[i][j];
        }
        sort(nums[i], nums[i]+M, greater<int>());
    }
    
    for(int i=0; i<M; i++){
        int m = 0;
        for(int j=0; j<N; j++){
            if(m <= nums[j][i]){
                m = nums[j][i];
            }
        }
        for(int j=0; j<N; j++){
            if(m == nums[j][i]){
                ans[j] += 1;
            }
        }
    }
    
    int res = *max_element(ans, ans+N);
    
    for(int j=0; j<N; j++){
        if(res == ans[j]){
            cout << j+1 << " ";
        }
    }
    
    return 0;
}



