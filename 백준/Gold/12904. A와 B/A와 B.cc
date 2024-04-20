#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 틀린 이유
// 방법 1)
    // 재귀로 푸니까 시간초과 에러 발생
// 방법 2)
    // deque를 사용해서 flag로 앞, 뒤 관리
    // 'B'가 나오면 flag 반전
    // 근데, 찾지 못한 반례가 있었던 듯
// 방법 3)
    // algorithm 헤더 파일의 reverse() 함수 사용
    // 라이브러리 함수 사용하는거라 시간 소요 많이 될 줄 알았는데 아니었다.~

int main(){ 
    string s, t;
    cin >> s;
    cin >> t;
    
    vector<char> v;
    
    for(auto c : t){
        v.push_back(c);
    }
    
    
    
    while(v.size() != s.length()){
        if(v.back() != 'A' && v.back() != 'B'){
            cout << "0";
            return 0;
        }
        else if(v.back() == 'A'){
            v.pop_back();
        }
        else if(v.back() == 'B'){
            v.pop_back();
            reverse(v.begin(), v.end());
        }
    }


    string str = "";
    for(auto c : v){
        str += c;
    }

    if(str == s)
        cout << "1";
    else 
        cout << "0";

    return 0;
}
