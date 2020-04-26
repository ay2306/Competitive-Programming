#include<bits/stdc++.h>
int main(){
    long long n,k;
    scanf("%lld %lld",&n,&k);
    if(k*(k-1) < n)return printf("NO\n"),0;
    printf("YES\n");
    for(int total = 0, gap = 1; total < n; gap++){
        for(int j = 1+gap; j <= k && total < n; ++j, ++total)printf("%d %d\n",j-gap,j);
        for(int j = k-gap; j > 0 && total < n; --j, ++total)printf("%d %d\n",j+gap,j);
    }
    return 0;
}

