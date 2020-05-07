#include<bits/stdc++.h>
using namespace std;

vector<int> a = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int main(){
    string s;
    int p = 0;
    for(int &i: a){
        cout << i << endl;
        cin >> s;
        if(s[0] == 'y')p++;
    }
    if(p > 1)return cout << "composite" << endl,0;
    if(p == 0)return cout << "prime" << endl,0;
    for(int &i: a){
        if(i*i > 100)break;
        cout << i*i << endl;
        cin >> s;
        if(s[0] == 'y')return cout << "composite" << endl,0;
    }
    return cout << "prime" << endl,0;
}