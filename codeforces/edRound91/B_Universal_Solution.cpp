#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    function<char(char)> win = [](char i)->char{
        return i == 'R' ? 'P' : ( i == 'P' ? 'S' : 'R');
    };
    while(t--){
        string a;
        cin >> a;
        map<char,int> m;
        for(char i: a)m[i]++;
        int mx = 0;
        for(auto i: m)mx = max(mx,i.second);
        for(auto i: m){
            if(i.second == mx){
                cout << string(a.size(),win(i.first)) << "\n";
                break;
            }
        }
    }
    return 0;
}