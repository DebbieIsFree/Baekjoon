#include <iostream>
using namespace std;

bool state[101]; // 1번부터 시작

int main(){
    int N; cin >> N;
    
    for(int i=1; i<=N; i++){
        cin >> state[i];
    }
    
    int P;  cin >> P;   // 남:1, 여:2
    
    for(int i=0; i<P; i++){
        int p, idx;
        cin >> p >> idx;
        
        if(p == 1){ // 남자 
            for(int i=idx; i<=N; i+=idx){
                state[i] = !state[i];
            }
        }
        else{ // 여자
            state[idx] = !state[idx];
            int left = idx-1;
            int right = idx+1;
            while((left >= 1  && right <= N) && (state[left] == state[right])){
                state[left] = !state[left];
                state[right] = !state[right];
                left--;
                right++;
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        cout << state[i] << " ";
        if(i % 20 == 0){
            cout << "\n";
        }
    }

    return 0;
}
