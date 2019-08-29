#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> inp[100];
    vector<string> s;
    for(int i = 0; i < n; ++i){
        string a;
        cin >>a;
        inp[a.length()-1].push_back(a);
    }
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < inp[i].size(); ++j){
            s.push_back(inp[i][j]);
        }
    }
    int pos = true;
    for(int i = 0; i+1 < s.size(); ++i){
        if(s[i+1].find(s[i]) == std::string::npos){
            pos = false;
        }
    }
    if(pos){
        cout << "YES\n";
        for(int i = 0; i < s.size(); ++i){
            cout << s[i] << endl;
        }
    }
    if(!pos){
        cout << "NO\n";
    }
}