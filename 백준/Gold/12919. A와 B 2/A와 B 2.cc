#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string S, T;
int ans = -1;

// 방법 1)
// func() 함수의 매개변수로 string을 줘서 시간초과가 발생하는줄 알고
// vector<char> v를 줬었는데, 그래도 똑같이 시간초과 발생

// 방법 2) 
// 그럼 '가지치기'를 해야 하나?
// string 의 find 함수 사용시 특정 문자열이 없을 경우 쓰레기 값이 나온다.
// 쓰레기 값 => string::npos ("no position")

void func(vector<char> v){
    string str = "";
    string str_rev = "";
        
    for(auto& c : v){
        str += c;
        str_rev = c + str_rev;
    }
    
    if(T.find(str) == string::npos && T.find(str_rev) == string::npos)
        return;
    
    if(v.size() == T.length()){
        if(str == T){
            ans = 1;
        }
        return;
    }
    
    vector<char> a = v;
    vector<char> b = v;
    
    a.push_back('A');
    b.push_back('B');
    reverse(b.begin(), b.end());
    
    func(a);
    func(b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> S >> T;
    
    vector<char> tmp;
    
    for(int i=0; i<S.length(); i++){
        tmp.push_back(S[i]);
    }
    
    func(tmp);

    if(ans == 1)
        cout << "1";
    else
        cout << "0";

    return 0;
}
