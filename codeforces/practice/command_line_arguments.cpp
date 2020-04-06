//https://codeforces.com/problemset/problem/291/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    getline(cin,a);
    vector<string> pos;
    bool sp = false;
    bool nm = false;
    string s = "";
    // cout << a << "\n";
    for(auto &i: a){
        if(i == ' ' && sp)s+=i;
        else if(i == ' ' && nm){
            pos.emplace_back(s);
            s = "";
            nm = false;
        }
        else if(i == '\"' && sp){
            pos.emplace_back(s);
            s = "";
            sp = false;
        }
        else if(i == '\"' && !sp){
            sp = true;
        }
        else if(i != ' '){
            s+=i;
            if(!sp)nm = true;
        }
    }
    if(!s.empty())pos.emplace_back(s);
    for(auto &i : pos){
        cout << "<" << i << ">\n";
    }
    return 0;
}