#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    vector<string> v;
    set<string> s;
    
    
    // 유효성 검사 시간 초과
    // 전화번호 아스키코드순으로 정렬
    // ex) "12", "123", "1234", "19", "199" ... 
//     sort(phone_book.begin(), phone_book.end());
    
//     for(int i=0; i<phone_book.size(); i++){
//         string number = phone_book[i];
        
//         if(!s.empty()){
//             for(string str : s){
//                 if(number.find(str) == 0){
//                     answer = false;
//                     return answer;
//                 }
//             }
//             s.insert(number);
//         }else{
//             s.insert(number);
//         }
//     }
    
    
    // 전화번호 아스키코드순으로 정렬
    // ex) "12", "123", "1234", "19", "199" ... 
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size()-1; i++){
        string str1 = phone_book[i];
        string str2 = phone_book[i+1];
        
        if(str2.find(str1) == 0){
            answer = false;
            return answer;
        }
    }
    
    return answer;
}
