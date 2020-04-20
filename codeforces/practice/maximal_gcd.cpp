//https://codeforces.com/contest/803/problem/C
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll n, k , g = 1, mnSum ,s = 0; 
    cin >> n >> k;
    if(k > int(2e5) || (k*(k+1))/2 > n)return cout << -1,0;
    mnSum = (k*(k+1))/2;
    for(ll i = 2; i*i <= n; ++i)
        if(n%i == 0){
            if(mnSum <= i)g = max(g,n/i);
            if(mnSum <= n/i)g = max(g,i);
        }
    for(ll i = 1; i < k; i++)printf("%lld ",(i*1LL*g)),s+=(i*g);
    printf("%lld\n",n-s);
    return 0;
}