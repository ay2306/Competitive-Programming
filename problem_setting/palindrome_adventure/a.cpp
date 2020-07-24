#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin >> a;
    map<char,int> m;
    for(char i: a)m[i]++;
    string ans = "";
    char c = 'z'+1;
    for(auto &i: m){
        ans+=string(i.second/2,i.first);
        i.second&=1;
        if(i.second)c = min(i.first,c);
    }
    cout << ans ;
    if(c != 'z'+1)cout << c;
    reverse(ans.begin(),ans.end());
    cout << ans ;
    return 0;
}