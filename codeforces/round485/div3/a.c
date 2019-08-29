#include<stdio.h>

int main(){
    int n, k,i;
    scanf("%d%d",&n,&k);
    int arr[100];
    int f[100] = {0};
    int dis = 0;
    int ans[100];
    for(i = 0; i < n; ++i){
        scanf("%d",&arr[i]);
        if(f[arr[i]-1]==0){
            ans[dis] = i+1;
            dis++;}
        f[arr[i]-1]++;
    }
    if(dis >= k){printf("YES\n");for(i = 0; i < k; ++i)printf("%d ",ans[i]);}
    if(dis < k)printf("NO");
}