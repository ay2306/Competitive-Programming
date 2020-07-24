//https://codeforces.com/contest/1342/problem/C
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long l,r,a,b,q,lcm;
        cin >> a >> b >> q;
        lcm = a*b/__gcd(a,b);
        if(a > b)swap(a,b);
        while(q--){
            cin >> l >> r;
            if(b%a == 0){
                cout << 0 << " ";
                continue;
            }
            long long first,last;
            first = l/lcm;
            last = r/lcm;
            long long ans = max(0LL,(last-first-1)*(b-1));
            first = first*lcm + b - 1;
            ans += max(0LL,first-l+1);
            ans += min(r,last*lcm+b-1) - lcm*last + 1;
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}