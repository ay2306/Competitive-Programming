#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    for(int &i: a)cin >> i;
    for(int &i: b)cin >> i;
    int ans = 0;
    for(int i: a){
        int f = i;
        while(i % 2 == 0)i/=2,ans++;
        for(int j = 3; j * j <= f; j+=2){
            while(i % j == 0)i/=j,ans++;
        }
        if(i > 1)ans++;
    }
    cout << ans << "\n";
    for(auto i: b){
        int prv = LLONG_MAX;
        for(auto j: a){
            int cnt = 0;
            while(j % i == 0)j/=i,cnt++;
            // cout << cnt << " " << prv << " ";
            prv = min(cnt,prv);
            ans -= 2*cnt;
            ans += prv;
        }
    }
    cout << ans ;
    return 0;
}