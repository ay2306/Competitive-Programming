#include<bits/stdc++.h>
using namespace std;

void solve(){
    string a;
    cin >> a;
    // if(a.length() % 2 == 1){
    //     cout << "NO\n";
    //     return ;
    // }
    map<char,int> m1,m2;
    for(int i = 0; i < a.length()/2; ++i){
        // cout << a[i+a.length()/2] << " " << i+a.length()/2 << endl;
        m1[a[i]]++;
        m2[a[i+a.length()/2 + (a.length()%2)]]++;
    }
    // cout << m2['a'] << endl;
    for(auto i:m1){
        // cout << i.first << " " << i.second << " " << m2[i.first] << endl;
        if(m2[i.first] != i.second){
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}