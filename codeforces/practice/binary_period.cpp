#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(is_sorted(s.begin(),s.end()) && s[0] == s.back())cout << s ;
        else for(int i = 0; i < s.size(); ++i)cout << "01";
        cout << "\n";
    }
    return 0;
}