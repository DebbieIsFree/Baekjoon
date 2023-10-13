#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int arr1[] = {1, 2, 3, 4, 5};       
    int arr2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int arr3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};    
    
    int res[3] = {0,0,0};
    
    int n1 = 0;
    for(int i=0; i<answers.size(); i++){
        if(n1 % 5 == 0){
            n1 = 0;
        }
        if(answers[i] == arr1[n1])
            res[0]++;
        n1++;
    }
    
    
    int n2 = 0;
    for(int j=0; j<answers.size(); j++){
        if(n2 % 8 == 0){
            n2 = 0;
        }
        if(answers[j] == arr2[n2])
            res[1]++;
        n2++;
    }
    
    
    
    int n3 = 0;
    for(int k=0; k<answers.size(); k++){
        if(n3 % 10 == 0){
            n3 = 0;
        }
        if(answers[k] == arr3[n3])
            res[2]++;
        n3++;
    }
    
    
    int m = 0;
    for(int i=0; i<3; i++){
        if(m < res[i]){
            m = res[i];
        }
    }
    
    for(int i=0; i<3; i++){
        if(m == res[i]){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}









