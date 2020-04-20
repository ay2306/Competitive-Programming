//https://codeforces.com/problemset/problem/1245/C
#include<bits/stdc++.h>
#define ll long long int
const int N = 1e5+100;
const int mod = 1e9+7;
ll fib[N] = {1,1,2},ans = 1,cnt;
char s[N],cur='.';

int main(){
    for(int i = 3; i < N; ++i)fib[i] = (fib[i-1]+fib[i-2])%mod;
    scanf("%s",s);
    for(int i = 0; s[i] != '\0'; ++i){
        if(s[i] == 'w' || s[i] == 'm')return printf("0"),0;
        else if(s[i] == cur && (s[i] == 'u' || s[i] == 'n'))cnt++;
        else if(s[i] != cur && (s[i] == 'u' || s[i] == 'n')){
            ans = ans*fib[cnt]%mod;
            cnt = 1;
            cur = s[i];
        }else{
            ans = ans*fib[cnt]%mod;
            cnt = 0;
            cur = s[i];
        }
    }
    ans = ans*fib[cnt]%mod;
    return printf("%lld\n",ans),0;
}