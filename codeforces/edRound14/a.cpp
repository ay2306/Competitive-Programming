#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int mx = max(1,n-1);
    int cnt = 0;
    while(n--){
        int a;
        cin >> a;
        cnt+=a;
    }
    if(cnt == mx)return void(cout << "YES\n");
    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}