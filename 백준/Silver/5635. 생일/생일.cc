#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

class C{
    public: 
    string tmp = "";
    string name = "";
    
    C(string tmp, string name){
        this->tmp = tmp;
        this->name = name;
    }
};

bool comp(const C& o1, const C& o2);

string strArr[100];
vector<C> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;  cin >> N;

    stringstream st;
    
    cin.ignore();
    
    for(int i=0; i<N; i++){
        getline(cin, strArr[i]);
    }
 
    for(int i=0; i<N; i++){
        st.str(strArr[i]);
        
        string tmp = "";
        string m = "", d = "", y = "";
        string name = "";
        
        string s;
        int idx = 0;
        
        while(st >> s){
            if(idx == 0){
                name = s;
            }
            else if(idx == 1){
                if(stoi(s) < 10){
                    s = "0"+ s;
                }
                d = s;
            }
            else if(idx == 2){
                if(stoi(s) < 10){
                    s = "0"+ s;
                }
                m = s;
            }
            else if(idx == 3){
                y = s;
            }
            idx++;
        }
        
        st.clear();
        
        tmp = y + m + d;
        
        // C c;
        // c.tmp = tmp;
        // c.name = name;
        
        v.push_back(C(tmp, name));
        // cout << "check c :" << c.name << endl;
    }
    
  
    sort(v.begin(), v.end(), comp);
    vector<C>::iterator last = v.end()-1;
    vector<C>::iterator first = v.begin();
    
    cout << (*last).name << "\n";
    cout <<  (*first).name;
    
    // cout << endl << endl;
    // for(int i=0; i<N; i++){
    //     cout << v[i].tmp << endl;
    // }
    
    // cout << endl << endl;
    // for(int i=0; i<N; i++){
    //     cout << v[i].name << endl;
    // }
    
  
    return 0;
}

bool comp(const C &o1, const C &o2) {
    return o1.tmp < o2.tmp;
}









