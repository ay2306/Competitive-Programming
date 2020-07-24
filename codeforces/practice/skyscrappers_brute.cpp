#include<bits/stdc++.h>
#define copy(a,b,n) for(int iter = 1; iter <= n; ++iter){a[iter] = b[iter];}
#define sum(a,n) accumulate(a+1,a+1+n,0LL)

using namespace std;
const int N = 1010;
long long arr[N],b[N],ans[N],mx;
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)scanf("%lld",arr+i);
    for(int i = 1; i <= n; ++i){
        copy(b,arr,n);
        for(int ind = i-1; ind >= 0; ind--)b[ind]=min(b[ind],b[ind+1]);
        for(int ind = i+1; ind <= n; ind++)b[ind]=min(b[ind],b[ind-1]);
        long long s = sum(b,n);
        if(s > mx){
            mx = s;
            copy(ans,b,n);
        }
    }
    for(int i = 1; i <= n; ++i)cout << ans[i] << " ";
    return 0;
}