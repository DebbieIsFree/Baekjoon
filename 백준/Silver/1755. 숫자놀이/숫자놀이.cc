#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N;
string num[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<pair<string, int>> ans;

bool comp(pair<string, int> &o1, pair<string, int> &o2){
    return o1.first < o2.first;
}

int main(){
    cin >> M >> N;
    
    for(int i=M; i<=N; i++){
        string str = to_string(i);
        string tmp = "";
        
        for(int j=0; j<str.length(); j++){
            int idx = str[j] - '0';
            tmp += num[idx];
            tmp += " ";
        }
        ans.push_back({tmp, i});
    }
    
    sort(ans.begin(), ans.end(), comp);
    
    int cnt = 0;
    for(int i=0; i<ans.size(); i++){
        cnt++;
        cout << ans[i].second << " ";
        if(cnt == 10){
            cnt = 0;
            cout << "\n";
        }
    }

    return 0;
}