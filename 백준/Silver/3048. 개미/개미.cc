#include <iostream>
#include <vector>
using namespace std;

class Info {
    public: 
    char name;
    char direction;
    
    public:Info(char name, char direction){
        this->name = name;
        this->direction = direction;
    };
};

class Change {
    public:
    int index1;
    int index2;
    
    public:Change(int idx1, int idx2){
        this->index1 = idx1;
        this->index2 = idx2;
    };
};


int main(){
    int n1, n2;
    cin >> n1 >> n2;
    
    string s1, s2;
    cin >> s1;
    cin >> s2;
    
    vector<Info> v;
    int index = -1;
    
    for(int i=n1-1; i>=0; i--){
        ++index;
        char name = s1[i];
        v.push_back(Info(name, 'R'));
    }
    
    for(int i=0; i<n2; i++){
        ++index;
        char name = s2[i];
        v.push_back(Info(name, 'L'));
    }
    
    int T;  cin >> T; 
    
    while(T--){
        vector<Change> list;
        
        for(int i=0; i<v.size()-1; i++){
            char dir1 = v[i].direction;
            char dir2 = v[i+1].direction;
            
            if(dir1 == 'R' && dir2 == 'L'){
               list.push_back(Change(i, i+1));
            }
        }
        
        int size = list.size();
        for(int i=0; i<size; i++){
            int idx1 = list[i].index1;
            int idx2 = list[i].index2;
            
            char name1 = v[idx1].name;
            char name2 = v[idx2].name;
            char nameTmp = v[idx1].name;
            
            char dir1 = v[idx1].direction;
            char dir2 = v[idx2].direction;
            char dirTmp = v[idx1].direction;
            
            v[idx1].name = name2;
            v[idx1].direction = dir2;
            v[idx2].name = nameTmp;
            v[idx2].direction = dirTmp;
        }
    }
    
    for(Info info : v){
        cout << info.name;
    }

    return 0;
}