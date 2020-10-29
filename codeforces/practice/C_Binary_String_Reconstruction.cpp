#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int x;
        cin >> x;
        string w(s.size(),'0'),ans="";
        for(int i = 0 ; i < s.size(); ++i){
            int cnt = 2;
            cnt -= (i - x >= 0 && s[i-x] == '0');
            cnt -= (i + x < s.size() && s[i+x] == '0');
            if(cnt == 2)w[i] = '1';
            else w[i] = '0';
        }
        for(int i = 0; i < s.size(); ++i){
            if((i-x >= 0 && w[i-x] == '1') || (i + x < w.size() && w[i+x] == '1'))ans+="1";
            else ans+="0";
        }
        if(ans != s)cout << "-1\n";
        else cout << w << "\n";
    }
    return 0;
}