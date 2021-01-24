#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n,s;
    cin >> n >> s;
    if(s == n)return cout << n+1,0;
    if(s > n)return cout << -1,0;
    auto f = [](int n, int b)->int{
        if(b == 1)return 0;
        // cout << n << " " << b << "\n";
        int ans = 0;
        while(n){
            ans += n%b;
            n/=b;
        }
        return ans;
    };
    int sq = sqrtl(n);
    for(int i = 1; i <= sq; ++i)
        if(f(n,i) == s)return cout << i,0;
    // In form P*B + Q = N, P+B = S
    for(int p = min(sq,s); p; --p){
        int q = s - p;
        int b = (n-q)/p;
        if(q >= b || p >= b || n-q < 0 || (n-q)%p != 0)continue;
        if(p*b + q == n){
            // cout << p << " " << b << " " << q << "\n";
            // cout << b*p + q << " " << p+q << "\n";
            return cout << (n-q)/p,0;
        }
    }
    cout << -1;
    return 0;
}