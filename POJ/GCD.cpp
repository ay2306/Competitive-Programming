#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;

int p[N],phi[N];

int power(int a, int n){
    if(n == 0)return 1;
    int p = power(a,n>>1);
    p *= p;
    if(n&1)p *= a;
    return p;
}   

int Phi(int n){
    if(n == 1)return 1;
    if(p[n] == n)return 1;
    int ans = 1;
    while(n > 1){
        int cnt = 0,k = p[n];
        while(n % k == 0){
            cnt++;
            n /= k;
        }
        ans *= (power(k,cnt) - power(k,cnt-1));
    }
    return ans;
}

int32_t main(){
    for(int i = 1; i < N; ++i)phi[i] = Phi(i);
    for(int i = 2; i < N; ++i)phi[i] += phi[i-1];
    int t,a,b,c,d,k;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&k);
        
    }
    return 0;
}