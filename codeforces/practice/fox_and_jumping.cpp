//https://codeforces.com/contest/510/problem/D
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[310],cost[310];
unordered_map<ll,ll> m;
int n;

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)scanf("%lld",arr+i);
    for(int i = 1; i <= n; ++i)scanf("%lld",cost+i);
    for(int i = 1; i <= n; ++i){
        ll k = arr[i], s = 1;
        for(int j = 2; j*j <= k; ++j)if(k%j == 0){s*=j;while(k%j==0)k/=j;}
        s*=k;
        for(auto &j: m){
            ll g = __gcd(s,j.first);
            if(m.find(g) != m.end())m[g] = min(m[g],cost[i]+j.second);
            else m[g] = cost[i]+j.second;
        }
        if(m.find(s) != m.end())m[s] = min(m[s],cost[i]);
        else m[s] = cost[i];
    }
    if(m.find(1LL)==m.end())m[1LL]=-1;
    printf("%lld",m[1]);
    return 0;
}