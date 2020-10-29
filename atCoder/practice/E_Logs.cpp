#include<bits/stdc++.h>
#define ld long double
using namespace std;
const ld eps = 1e-9;
int main(){
    long long n,k;
    cin >> n >> k;
    vector<ld> a(n);
    for(auto &i: a)cin >> i;
    ld hi = *max_element(a.begin(),a.end());
    ld lo = 0;
    ld ans = hi;
    for(int steps = 0; steps < 100; steps++){
        ld mid = (lo + hi) / 2.0;
        long long req = 0;
        for(auto i: a)req += (long long)(i-eps)/mid;
        if(req <= k)ans = mid,hi = mid;
        else lo = mid;
    }
    cout << (int)ceil(ans);
    return 0;
}