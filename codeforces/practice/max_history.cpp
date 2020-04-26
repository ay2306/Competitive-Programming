//https://codeforces.com/contest/938/problem/E
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e6+10;
const ll mod = 1e9+7;
ll ifct[N],fct[N],inv[N],n,arr[N],ans,prv;
void pre(){
    ifct[1] = ifct[0] = fct[0] = fct[1] = 1;
    inv[1] = 1;
    for(ll i = 2; i < N; ++i)fct[i]=i*fct[i-1]%mod,inv[i] = (mod-(mod/i)*inv[mod%i]%mod)%mod; 
    for(ll i = 2; i < N; ++i)ifct[i]=inv[i]*ifct[i-1]%mod;
}
ll ncr(ll n, ll r){
    if(r > n || r < 0)return 0;
    return fct[n]*ifct[n-r]%mod*ifct[r]%mod;
} 
int main(){
    pre();
    scanf("%lld",&n);
    for(int i = 1; i <= n; ++i)scanf("%lld",arr+i);
    sort(arr+1,arr+n+1);
    for(int i = 1; arr[i] < arr[n]; ++i){
        if(arr[i] == arr[i-1]){ans=(ans+prv)%mod; continue;}
        prv = ncr(n,n-i+1)*fct[i-1]%mod*fct[n-i]%mod;
        prv = (prv*arr[i])%mod;
        ans = (ans+prv)%mod;
    }
    return printf("%lld\n",ans),0;
}