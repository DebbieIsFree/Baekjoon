#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<string, int> &n1, pair<string, int> &n2){
    if(n1.first.length () == n2.first.length()){
        if(n1.second == n2.second){
            return n1.first < n2.first;
        }else{
            return n1.second < n2.second;
        }
    }else{
        return n1.first.length() < n2.first.length();
    }
}

int main(){
    int N;  cin >> N;
    string str;
    
    vector<pair<string, int>> s;
    
    while(N--){
        cin >> str;
        int sum = 0;
        
        for(int i=0; i<str.length(); i++){
            if(str[i] >= '0' && str[i] <= '9'){
                sum += str[i] - '0';
            }
        }
        
        s.push_back({str, sum});
    }
    
    sort(s.begin(), s.end(), comp);
    
    for(auto e : s){
        cout << e.first << "\n";
    }

    return 0;
}