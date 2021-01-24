#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(char &i: s)i-='0';
    int o = accumulate(s.begin(),s.end(),0), z = s.size() - o;
    cout << min(2+z,o);
    return 0;
}