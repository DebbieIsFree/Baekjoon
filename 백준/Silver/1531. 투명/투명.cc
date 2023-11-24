#include <iostream>

using namespace std;

int arr[101][101] = {0,};

int main(){
    
    int N, M;
    cin >> N >> M;
    
    while(N--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int i=y1; i<=y2; i++){
            for(int j=x1; j<=x2; j++){
                arr[101-i][j] += 1;
            }
        }
    }
    
    int answer = 0;
    
    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            if(arr[i][j] > M){
                answer++; 
            }
        }
    }

    cout << answer;
    
    return 0;
}
