#include <string>
#include <vector>
using namespace std;

int zero = 0, one = 0;
vector<vector<int>> v;

void func(int row, int col, int sz){
    if(sz == 1){
        if(v[row][col] == 0)
            zero++;
        else 
            one++;
        return;
    }
    
    bool flag = false;
    
    for(int i=row; i<row+sz; i++){
        for(int j=col; j<col+sz; j++){
            if(v[row][col] != v[i][j]){
                flag = true;
                break;
            }
        }
    }
    if(!flag){
        if(v[row][col] == 0)    
            zero += 1;
        else
            one += 1;
    }else{
        int nsz = sz/2;
        func(row, col, nsz);
        func(row+nsz, col, nsz);
        func(row, col+nsz, nsz);
        func(row+nsz, col+nsz, nsz);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    v = arr;
    
    int sz = arr.size();
    
    func(0, 0, sz);
    
    answer.push_back(zero);
    answer.push_back(one);
    
    return answer;
}