#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int N, M;

vector<map<char, int>> v(50);
string strArr[1000];

int main(){
    cin >> N >> M;
    
    for(int i=0; i<N; i++){     // 문자열 개수 (N)
        string str; cin >> str;
        strArr[i] = str;
        
        for(int i=0; i<M; i++){     // 문자열 길이 (M)
            char c = str[i];
            
            if(v[i].find(c) != v[i].end()){
                v[i][c] += 1;
            }else{
                v[i].insert(make_pair(c, 1));
            }
        }
    }
    
    string res = "";
    
    for(int i=0; i<M; i++){
        int max = 0;
        string mword;
        for(int j=0; j<v[i].size(); j++){
            for (auto iter : v[i]) {
	        	if(max < iter.second){
	        	    max = iter.second;
	        	    mword = iter.first;
	        	}
	        }
        }
        res += mword;
    }
    
    
    
    int num = 0;
    for(int i=0; i<N; i++){     // 문자열 개수 (N)
        for(int k=0; k<M; k++){     // 문자열 길이 (M)
            if(strArr[i][k] != res[k]){
                num++;
            }
        }
    }    
    
    cout << res << "\n";
    cout << num;
    
    // for(auto iter : v[7]){
    //     cout << iter.first << " " << iter.second << endl;
    // }
    
    // for(int i=0; i<M; i++){
    //     for(int j=0; j<v[i].size(); j++){
    //         for (auto iter : v[i]) {
	   //     	cout << iter.first << " " << iter.second << endl;
	   //     }
    //     }
    // }
    
    return 0;
}
