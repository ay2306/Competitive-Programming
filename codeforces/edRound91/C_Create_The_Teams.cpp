#include<bits/stdc++.h>
#define int long long 
using namespace std;

void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int &i: a)cin >> i;
    sort(a.begin(),a.end(),greater<int>());
    int cur = 1,ans = 0,cnt = 0,mn;
    for(int i: a){
        mn = i;
        cnt++;
        if(cnt * mn >= x){
            ans++;
            cnt = 0;
        }
    }
    cout << ans << "\n";
}

signed main(){
    int t;
    cin >> t;
    while(t--)solve();
}