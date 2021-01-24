#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q,l,r;
    cin >> n >> q;
    string s;
    cin >> s;
    while(q--){
        cin >> l >> r;
        l--,r--;
        bool k = true;
        for(; l < r; ++l, r--){
            if(s[l] != s[r]){
                k = false;
                break;
            }
        }
        if(!k)cout << "no\n";
        else cout << "yes\n";
    }    
    return 0;
}
