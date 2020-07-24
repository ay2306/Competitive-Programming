//https://codeforces.com/contest/1342/problem/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long x,y,a,b;
        cin >> x >> y >> a >> b;
        if(x > y)swap(x,y);
        long long ans = b*x + a*(y-x);
        ans = min(ans,a*(x+y));
        cout << ans << "\n";
    }
    return 0;
}