#include <string>
#include <vector>

using namespace std;

int solution(vector<int> v) {
    int answer = 0;
    vector<int>::iterator iter = v.end() - 1;
    int last = *iter;
    
    if(v[1] - v[0] == v[2] - v[1]){
        answer = last + (v[1] - v[0]);
    }else{
        if(v[1] / v[0] == 0){
            answer = last / (v[0] / v[1]);    
        }else{
            answer = last * (v[1] / v[0]);
        }
    }    

    return answer;
}