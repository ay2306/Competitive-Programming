//https://codeforces.com/contest/258/problem/C
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
const long long mod = 1e9+7;
int a,n,arr[N];
long long ans,diff[N];
long long power(long long a, long long n){
    if(n == 0)return 1;
    if(n == 1)return a;
    long long p = power(a,n/2);
    p = p * p % mod;
    if(n & 1)p = p * a % mod;
    return p;
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)scanf("%d",arr+i);
    sort(arr,arr+n);
    for(int i = 1; ; ++i){
        if(arr[n-1] < i)break;
        vector<int> factors(1,arr[n-1]+1);
        for(int j = 1; j*j <= i; ++j){
            if(i % j)continue;
            factors.emplace_back(j);
            if(j * j != i)factors.emplace_back(i/j);
        }
        int k = (int)factors.size();
        sort(factors.begin(),factors.end());
        vector<int> cnt(k-1,0);
        for(int j = 0; j+1 < k; ++j){
            int s1 = lower_bound(arr,arr+n,factors[j+1]) - arr;
            int s2 = (lower_bound(arr,arr+n,factors[j]) - arr);
            cnt[j] = s1 - s2;
        }
        long long res = 1;
        for(int j = 0; j+1 < k; ++j){
            if(j+2 != k)res = res * power(j+1,cnt[j]) % mod;
            else{
                if(cnt.back()!=1)
                    res = res*((power(j+1,cnt.back())-power(j,cnt.back()) + mod)%mod) % mod;
            } 
        }
        if(res == 0)res++;
        ans += res;
        if(ans >= mod)ans-=mod;
    }
    return printf("%lld\n",ans),0;
}