#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
long long n,m,s,i,j,ans,a[N];
int main(){
    scanf("%lld %lld",&n,&m);
    for(i = 1; i <= n; ++i)scanf("%lld",a+i);
    for(i = 1, j = 1, s = 0; j <= n; ++j){
        s+=a[j];
        while(s > m)s-=a[i++];
        ans = max(ans,s);
    }
    return printf("%lld\n",ans),0;
}