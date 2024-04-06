#include <iostream>
#include <algorithm>
using namespace std;

int N;
int operand[4];      // +, -, x, / 
int nums[12];

int min_ans = 1e9;
int max_ans = -1e9;

// 틀린 이유 : 맨처음에 operand[4]를 전역변수로 설정하고, perm함수를 재귀적으로 
// 들어갈 때마다 이 전역변수의 개수를 변경했는데, 그러면 재귀적으로 들어갈 때마다 
// 다른 operand[4]의 상태를 추적하지 못해서 원하는 결과가 나오지 않는다.
// 따라서 perm 함수에 매개변수를 하나 더 줘야한다.

void perm(int cnt, int nextIdx, int sum, int op[4]){
    if(cnt == N-1){
        min_ans = min(min_ans, sum);
        max_ans = max(max_ans, sum);
        return;
    }
    
    // 연산자가 없으면 그 연산자로 계산 불가
    if(op[0] > 0){
        op[0] -= 1;
        perm(cnt+1, nextIdx+1, sum + nums[nextIdx], op);
        op[0] += 1;
    }
    if(op[1] > 0){
        op[1] -= 1;
        perm(cnt+1, nextIdx+1, sum - nums[nextIdx], op);
        op[1] += 1;
    }
    if(op[2] > 0){
        op[2] -= 1;
        perm(cnt+1, nextIdx+1, sum * nums[nextIdx], op);
        op[2] += 1;
    }
    if(op[3] > 0){
        op[3] -= 1;
        perm(cnt+1, nextIdx+1, sum / nums[nextIdx], op);
        op[3] += 1;
    }    
}


int main(){
    int T; cin >> T;
    
    for(int tc=1; tc<=T; tc++){
        cin >> N;   
        
        // 연산자 개수 입력 받기
        for(int i=0; i<4; i++){
            cin >> operand[i];
        }
        
        // 숫자 입력 받기
        for(int i=0; i<N; i++){
            cin >> nums[i];
        }
        
        min_ans = 1e9;  
        max_ans = -1e9;
        
        perm(0, 1, nums[0], operand);
        
        cout << "#" << tc << " " << max_ans - min_ans << "\n";
    }
    

    return 0;
}

