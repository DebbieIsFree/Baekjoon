#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    
    vector<int> answer(photo.size());
    
    map<string ,int> m;
    for(int i=0; i<name.size(); i++){
        m[name[i]] = yearning[i];
    }
    
    for(int i = 0; i < photo.size(); i++){    // 사진 개수
        for(int k = 0; k < photo[i].size(); k++){     // 사진 속 이름 개수
            for(int j = 0; j < name.size(); j++){     // 이름 벡터 for문
                 
                if(photo[i][k] == name[j]){     // i번째 사진 속 k와 이름이 같으면..
                    answer[i] += yearning[j];    
                }
            }
        }
    }
    
    
    return answer;
}