#include <iostream>

using namespace std;

int N, M;
int map[50][50];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        string str; cin >> str;
        for(int j=0; j<str.length(); j++){
            map[i][j] = str[j] - '0';
        }
    }
    
    int smaller;
    N > M ? smaller = M : smaller = N;
    
    int result = 1;
    
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){ 
    //         for(int k=2; k<=smaller; k++){  // 정사각형 크기
    //             if(i+k < 0 || i+k > N || j+k < 0 || j+k > M)
    //                 continue;
    //             if(map[i][j] == map[i+k][j] && (map[i][j] == map[i][j+k] && map[i][j] == map[i+k][j+k])){
    //                 if(result < smaller * smaller){
    //                     result = smaller * smaller;
    //                 }
    //             }
    //         }
    //     }
    // }
    
    for(int k=2; k<=smaller; k++){  // 정사각형 크기
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){ 
                if(i+k-1 < 0 || i+k-1 >= N || j+k-1 < 0 || j+k-1 >= M)
                    continue;
                if(map[i][j] == map[i+k-1][j] && (map[i][j] == map[i][j+k-1] && map[i][j] == map[i+k-1][j+k-1])){
                    if(result < k * k){
                        result = k * k;
                    }
                }
            }    
        }
    }
    
    cout << result;

    return 0;
}
