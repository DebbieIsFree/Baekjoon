#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool check[10000000] = {0,};
bool idxCheck[8] = {0,};

bool sosu(int num){
    if(num <= 1)
        return false;
    for(int i=2; i<num; i++){
        if(num % i == 0)
            return false;       // 소수가 아니다
    }
    return true;      // 소수이다.
}

void recursion(string tmp, int idx, string numbers){
    if(tmp.length() == numbers.length())
        return;
    
    for(int i=0; i<numbers.length(); i++){
        if(idxCheck[i]){
            continue;
        }
        else {
            int n = stoi(tmp + numbers[i]);
            if(!check[n] && sosu(n)){
                check[n] = true;
                answer++;
            }
            idxCheck[i] = true;
            recursion(tmp+numbers[i], i, numbers);    
            idxCheck[i] = false;
        }
    }
}

int solution(string numbers) {    
    for(int i=0; i<numbers.length(); i++){
        string tmp = "";
        tmp += numbers[i];
        int tn = stoi(tmp);
        if(!check[tn] && sosu(tn)){
            check[tn] = true;
            answer++;
        }
        idxCheck[i] = true;
        recursion(tmp, i, numbers);
        idxCheck[i] = false;
    }
    
    return answer;
}



