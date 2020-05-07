#include<bits/stdc++.h>
using namespace std;
const int N = (1<<13);

int a[N];

int main(){
    int n, ans = 0;
    scanf("%d",&n);
    for(int i = 2; i < (1 << n+1); ++i)scanf("%d",a+i);
    for(int i = (1 << n+1)-1; i > 1; i-=2){
        ans+=abs(a[i]-a[i-1]);
        a[i>>1]+=max(a[i],a[i-1]);
    }
    return printf("%d",ans),0;
}