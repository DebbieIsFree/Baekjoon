#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    
    for(int i=0; i<elements.size(); i++){
        int n = elements[i];
        s.insert(n);
        
        for(int j=i+1; j<i+elements.size(); j++){
            // 맨 마지막에서 처음으로 연속한다고 가정하면,
            // [7,9,1,1,4] 5개일 때
            // 맨 마지막(인덱스 4) --> 제일 처음(인덱스 0)
            // 인덱스 계산하기 위해서 % 연산자 사용
            int idx = j % elements.size();
            n += elements[idx];
            s.insert(n);
        }
    }
    
    
    answer = s.size();
    
    return answer;
}