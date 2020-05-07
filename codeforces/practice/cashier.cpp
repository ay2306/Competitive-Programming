//https://codeforces.com/contest/1059/problem/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long ans = 0, n = 0, t,L,a,l,rem,cur = 0;
    cin >> n >> L >> a;
    while(n--){
        cin >> t >> l;
        ans+=(t-cur)/a;
        cur = t+l;
    }
    ans+=(L-cur)/a;
    return cout << ans,0;
}