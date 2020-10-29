#include<bits/stdc++.h>
#define int long long
using namespace std;

int choose2(int n){
    return n*(n-1)/2;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        int m,d,w;
        cin >> m >> d >> w;
        m--;
        int g = __gcd(d-1,w);
        w/=g;
        m = min(d-1,m);
        // upto m%w there m/w + 1 appearance
        int ans = (m%w+1) * choose2(m/w+1);
        //after m%w to w-1 there are m/w appearances
        ans += (w-1 - m%w) * choose2(m/w);
        cout << ans << "\n";
    }
    return 0;
}