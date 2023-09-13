#include <iostream>

using namespace std;

int alph[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;  cin >> str;
    
    for(int i=0; i<str.length(); i++){
        int idx = str[i] - 'A';
        alph[idx] += 1;
    }
    
    int cnt = 0;
    for(int i=0; i<26; i++){
        if(alph[i] % 2 == 1){
            cnt++;
        }
    }
    
    if(cnt > 1){
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    
    string left = "", mid = "", right = "";
    
    for(int i=0; i<26; i++){
        char c = (char)('A' + i);
        while(alph[i] / 2 != 0){
            left = left + c;
            right = c + right;
            // cout << right << "\n";
                
            alph[i] = alph[i] - 2;
        }
        
        if(alph[i] == 1){
            mid = mid + c;
            // cout << mid << "\n";
        }
    }
    
    cout << left + mid + right;

    return 0;
}
