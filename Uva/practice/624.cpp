#include<bits/stdc++.h>
int n,k,mask,arr[20];
int main(){
    while(scanf("%d",&n) != EOF){
        int value = 0, ans = 0;
        scanf("%d",&k);
        for(int i = 0; i < k; ++i)scanf("%d",arr+i);
        for(mask = 0; mask < (1 << k); ++mask){
            int cur = 0;
            for(int j = 0; j < k; ++j)if((mask>>j)&1)cur+=arr[j];
            if(cur > value && cur <= n)ans = mask, value = cur;
            else if(cur == value && __builtin_popcount(mask) > __builtin_popcount(ans))ans = mask, value = cur;
        }
        for(int j = 0; j < k; ++j)if((ans>>j)&1)printf("%d ",arr[j]);
        printf("sum:%d\n",value);
    }
    return 0;
}