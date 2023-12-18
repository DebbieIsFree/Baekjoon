#include <iostream>
#include <set>
#include <string>
using namespace std;

int N, K;
int card[10];
int res = 0;

set<int> s;
bool visited[10];

void func(int cnt, string num){
    if(cnt == K){
        res++;
        s.insert(stoi(num));
        return;
    }
    
    for(int i=0; i<N; i++){
        if(!visited[i]){
            visited[i] = true;
            func(cnt+1, num + to_string(card[i]));
            visited[i] = false;
        }
    }
}


int main(){
    
    cin >> N;
    cin >> K;
    
    for(int i=0; i<N; i++){
        cin >> card[i];
    }
    
    for(int i=0; i<N; i++){
        visited[i] = true;
        func(1, to_string(card[i]));
        visited[i] = false;
    }

    cout << s.size();

    return 0;
}

