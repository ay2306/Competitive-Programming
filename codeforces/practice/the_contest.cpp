//https://codeforces.com/contest/1257/problem/E
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5+10;
int v1[N],v2[N],v3[N],dp[N];
int k1,k2,k3,a,n;

int main(){
    scanf("%d%d%d",&k1,&k2,&k3);
    for(int i = 0; i < k1; ++i)scanf("%d",v1+i);
    for(int i = 0; i < k2; ++i)scanf("%d",v2+i);
    for(int i = 0; i < k3; ++i)scanf("%d",v3+i);
    sort(v1,v1+k1);
    sort(v2,v2+k2);
    sort(v3,v3+k3);
    dp[0] = k3;
    for(int i = 1; i <= k1+k2+k3; ++i){
        dp[i] = dp[i-1];
        int element = k1+k2+k3+1-i;
        if(binary_search(v2,v2+k2,element))dp[i]++;
        if(binary_search(v3,v3+k3,element))dp[i]--;
    }
    for(int i = 1; i <= k1+k2+k3; ++i){
        dp[i] = min(dp[i-1],dp[i]);
    }
    int ans = INT_MAX;
    for(int i = 0; i <= k1+k2+k3; ++i){
        int extra = k1 - (upper_bound(v1,v1+k1,i)-v1);
        int missing = max(0,i-(k1-extra));
        int K = upper_bound(v3,v3+k3,i) - v3;
        ans = min(ans,extra+missing+dp[k1+k2+k3-i]-K);
    }
    printf("%d\n",ans);
    return 0;
}