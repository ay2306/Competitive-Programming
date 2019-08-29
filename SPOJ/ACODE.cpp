#include <bits/stdc++.h>
#define ll long long int
ll dp[6000];
char a[6000];
int getInt(char a, char b){
    return (a-'0')*10 + (b-'0');
}
int main(){
    while(1){
        scanf("%s",a+1);
        int n = strlen(a+1);
        if(a[1] == '0')break;
        dp[1] = 1;
        dp[0] = 1;
        for(int i = 2; a[i] != '\0'; ++i){
            if(a[i] == '0'){
                dp[i] = dp[i-2];
            }else{
                dp[i] = dp[i-1];
                if(a[i-1] != '0' && getInt(a[i-1],a[i]) <= 26)dp[i] += dp[i-2];
            }
            // printf("i = %d, char = %c, dp = %lld\n",i,a[i],dp[i]);
        }
        std::cout << dp[n] << "\n";
    }
   return 0;
}