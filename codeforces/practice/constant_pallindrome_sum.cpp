//https://codeforces.com/contest/1343/problem/D
#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int a,n,k,t;
    scanf("%d\n",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        vector<int> diff(2*k+10,0),arr(n,0),freq(2*k+1,0);
        for(int &i: arr)scanf("%d",&i);
        for(int i = 0, j = n-1; i < j; ++i,--j)diff[min(arr[i],arr[j])+1]++,diff[max(arr[i],arr[j])+k+1]--,freq[arr[i]+arr[j]]++;
        for(int i = 2; i < 2*k+10; ++i)diff[i]+=diff[i-1];
        int ans = INT_MAX;
        for(int i = 2; i < 2*k+1; ++i)printf("x = %d, diff[x] = %d, freq[x] = %d\n",i,diff[i],freq[i]);
        for(int i = 2; i < 2*k+1; ++i)ans = min(ans,2*(n/2-diff[i])+diff[i]-freq[i]);
        printf("%d\n",ans);
    }

    return 0;
}