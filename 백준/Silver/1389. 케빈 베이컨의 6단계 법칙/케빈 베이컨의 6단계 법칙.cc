#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[101][101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    fill(&arr[0][0], &arr[0][0] + 101 * 101, 987654321);
    
    while(M--){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    
    for(int m=1; m<=N; m++){
        for(int s=1; s<=N; s++){
            for(int e=1; e<=N; e++){
                if(arr[s][e] > arr[s][m] + arr[m][e]){
                    arr[s][e] = arr[s][m] + arr[m][e];
                }
            }    
        }
    }

    int minVal = 987654321;
    int ans = 1;
    
    for(int i=1; i<=N; i++){
        int sum = 0;
        for(int j=1; j<=N; j++){
            if(i == j)
                continue;
            sum += arr[i][j];
        }
        if(minVal > sum){
            minVal = sum;
            ans = i;
        }
    }
    
    
    cout << ans;

    return 0;
}