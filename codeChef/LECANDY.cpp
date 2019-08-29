#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,c,a,s=0;
    cin >> n >> c;
    for(int i = 0; i < n; ++i){
        cin >> a;
        s+=a;
    }
    if(s <= c)cout << "Yes\n";
    else cout << "No\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}