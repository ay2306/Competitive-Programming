#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pref[26];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 26; ++j)pref[j].emplace_back(i ? pref[j][i-1] : 0);
        pref[s[i]-'a'][i]++;
    }
    int q,r,l;
    cin >> q;
    while(q--){
        cin >> l >> r;
        l--,r--;
        if(l == r)cout << "Yes\n";
        else if (s[l] != s[r])cout << "Yes\n";
        else {
            int cnt = 0;
            for(int i = 0; i < 26; ++i){
                cnt += (pref[i][r] - (l ? pref[i][l-1] : 0)) > 0;
            }
            if(cnt > 2)cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}