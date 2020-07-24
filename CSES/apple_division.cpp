#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,arr[21],ans=LLONG_MAX;
    scanf("%lld",&n);
    for(int i = 0; i < n; ++i)scanf("%lld",arr+i);
    // for(int i = 0; i < (1 << n); ++i){
    //     int sum = 0;
    //     for(int j = 0; j < n; ++j){
    //         if((i>>j)&1)sum+=arr[j];
    //         else sum-=arr[j];
    //     }
    //     ans = min(ans,abs(sum));
    // }
    sort(arr,arr+n,greater<int>());
    int s1 = 0, s2 = 0;
    for(int i = 0; i < n; ++i){
        if(s1 <= s2)s1+=arr[i];
        else s2+=arr[i];
    }
    return printf("%lld",abs(s1-s2)),0;
}