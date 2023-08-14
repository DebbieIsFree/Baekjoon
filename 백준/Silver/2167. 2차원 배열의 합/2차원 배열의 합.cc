#include <iostream>
using namespace std;

int arr[301][301];
long long sum[301][301];

int main(){
    int N, M, K;
    cin >> N >> M;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> arr[i][j];            
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + arr[i][j];    
        }
    }
    
    cin >> K;
    
    while(K--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
    
        cout << sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] << "\n";
    }


    return 0;
}
