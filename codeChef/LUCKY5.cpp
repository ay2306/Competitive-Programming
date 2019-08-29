#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        int ans = 0;
        for(auto &i: a)ans+=(!(i == '4' || i == '7'));
        cout << ans << "\n";
    }
    return 0;
}