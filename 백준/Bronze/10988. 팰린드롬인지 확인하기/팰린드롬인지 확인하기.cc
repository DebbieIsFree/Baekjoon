#include <iostream>

using namespace std;

int main(){
    
    string str;  cin >> str;
    
    int left = 0;
    int right = str.length() - 1;
    
    while(left < right){
        if(str[left] == str[right]){
            left++;
            right--;
        }
        else{
            cout << "0";
            return 0;
        }
    }

    cout << "1";
    
    return 0;
}
