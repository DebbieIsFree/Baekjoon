#include <iostream>
using namespace std;

int alphabet[26];

int main(){
    string str;
    cin >> str;

    for(int i=0; i <str.size(); i++){
        int idx = str[i] - 97;
        alphabet[idx] += 1;
    }

    for(int i=0; i <26; i++){
        cout << alphabet[i] << " "; 
    }

    return 0;
}