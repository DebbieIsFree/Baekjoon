#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int ranking(int cnt);

vector<int> solution(vector<int> lottos, vector<int> win) {
    vector<int> answer;
    
    sort(lottos.begin(), lottos.end());
    sort(win.begin(), win.end());
    
    int cnt = 0;
    int zeros = 0;
    
    for(int i=0; i<6; i++){
        if(lottos[i] == 0){
            zeros++;
            continue;
        }
        auto it = find(win.begin(), win.end(), lottos[i]);
        if(it != win.end()){
            cnt++;
        }
    }
    
    int high = ranking(cnt+zeros);
    int low = ranking(cnt);
    
    answer.push_back(high);
    answer.push_back(low);
    
    
    return answer;
}

int ranking(int cnt){
    switch (cnt){
        case 6:{ return 1;}
        case 5 :{return 2;}
        case 4: {return 3;}
        case 3: {return 4;}
        case 2 : {return 5;}
        default : return 6;   
    }
}