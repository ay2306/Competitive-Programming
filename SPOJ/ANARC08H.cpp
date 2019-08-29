#include<cstdio>
#define ll long long int
const int N = 1e6+10;
int dp[N];

int main(){
    while(1){
        int n,k;
        scanf("%d %d",&n,&k);
        if(n == 0 && k == 0)break;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i] = (dp[i-1]+k-1)%(i) + 1;
        }
        printf("%d %d %d\n",n,k,dp[n]);
    }
    return 0;
}