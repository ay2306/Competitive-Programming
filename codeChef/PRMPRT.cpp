#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int pr[N];
int main(){
    for(int i = 2; i < N; ++i){
        if(!pr[i])for(int j = 2*i; j < N; j+=i)pr[j]==0?pr[j]=i:pr[j]=min(pr[j],i);
    }
    int n,q,a,b;
    scanf("%d%d",&n,&q);
    while(q--){
        scanf("%d%d",&a,&b);
        if(pr[a] && !pr[b])swap(a,b);
        // printf("%d %d\n",a,b); 
        if(a == b)printf("0\n");
        else if (!pr[a] && b % a == 0)printf("1\n");
        else if (!pr[a] && !pr[b] && a*1LL*b <= 1LL*n)printf("2\n");
        else if (__gcd(a,b) != 1)printf("2\n");
        else if (!pr[a] && pr[b] && a*1LL*pr[b] <= 1LL*n)printf("3\n");
        else if (pr[a] && pr[b] && pr[a]*1LL*pr[b] <= 1LL*n)printf("4\n");
        else if (!pr[a] && !pr[b] && 2*a <= n && 2*b <= n)printf("4\n");
        else if (!pr[a] && pr[b] && 2*a <= n && 2*pr[b] <= n)printf("5\n");
        else if (pr[a] && pr[b] && 2*pr[a] <= n && 2*pr[b] <= n)printf("6\n");
        else printf("-1\n");
    }
    return 0;
}