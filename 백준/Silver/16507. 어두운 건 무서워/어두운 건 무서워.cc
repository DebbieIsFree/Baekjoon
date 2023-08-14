#include <iostream>
using namespace std;

int arr[1001][1001];
long long sum[1001][1001];

int main(){
    int R, C, Q;
    cin >> R >> C >> Q;
    
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
        }
    }

    while(Q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int size = (x2-x1+1) * (y2-y1+1);
        long long res = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
        res /= size;
        cout << res << "\n";
    }

    return 0;
}
