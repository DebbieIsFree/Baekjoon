#include <iostream>
#include <map>
using namespace std;


int main(){
    
    int N;
    cin >> N;
    
    map<string, int> book;
    int m = 0;
    
    
    while(N--){
        string name;    cin >> name;
        if(book.find(name) == book.end()){
            book.insert(make_pair(name, 1));
        }
        else{
            book[name] += 1;
        }
    }
    
    string answer = "";
    
    for(auto iter : book){
        if(m < iter.second){
            m = iter.second;
            answer = iter.first;
        }
    }

    cout << answer;

    return 0;
}


