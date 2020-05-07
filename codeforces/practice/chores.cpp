#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,x,a[110];
    scanf("%d%d%d",&n,&k,&x);
    for(int i = 0; i < n; ++i)scanf("%d",a+i);
    for(int i = n-1; i >= n-k; --i)a[i] = min(a[i],x);
    return printf("%d",accumulate(a,a+n,0)),0;
}