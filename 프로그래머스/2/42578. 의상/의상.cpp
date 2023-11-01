#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    // 이 문제는 '확률', 경우의 수 문제이다.
    // 각 카테고리에 대해서 
    // 선택안 할 수도 있고, n개 중 1개를 선택할 수도 있다.
    // 따라서 각 카테고리 별로 n+1(선택 안 하는 경우)의 경우의 수가 나오고
    // 이것들을 곱하면 된다. 
    // 단, 모든 카테고리를 선택하지 않는 경우(1)를 빼주면 된다.
    
    map<string, int> m;
    
    for(int i=0; i<clothes.size(); i++){
        if(m.find(clothes[i][1]) == m.end()){
            m.insert({clothes[i][1], 1});
        }
        else 
            m[clothes[i][1]] += 1;
    }
    
    map<string, int>::iterator it = m.begin();
    
    while(it != m.end()){
        int tmp = (*it).second + 1;
        answer *= tmp;
        it++;
    }
    
    answer -= 1;
    
    
    return answer;
}


