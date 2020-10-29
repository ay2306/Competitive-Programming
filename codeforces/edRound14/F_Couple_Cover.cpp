#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e6+5;
const int M = 3e6;
// const int N = 20;
// const int M = 15;
int F[N], cnt[N], arr[N];
int q,x,n;

signed main(){
    scanf("%lld",&n);
    for(int i = 0; i < n; ++i)scanf("%lld",arr+i);
    sort(arr,arr+n);
    for(int i = 0; i < n; ++i)F[arr[i]]++;
    for(int i = N-1; i; --i)F[i-1] += F[i];
    for(int i = 1; i < N; ++i){
        int mult = 1;
        int sq = i * i;
        int ff = F[i] - F[i+1];
        if(!ff)continue;
        // printf("i = %lld, ff = %lld, sq = %lld :\n",i,ff,sq);
        for(int j = i; j <= M; j+=i,mult++){
            int f = F[mult]-F[mult+1];
            int add = 0;
            if(j != sq)add=f*ff;
            else{
                add=f*(f-1);
            }
            // printf("%j = %lld, mult = %lld, f = %lld, add = %lld\n",j,mult,f,add);
            cnt[j]+=add;
        }
        int add = F[mult]*ff-ff*(mult <= i);
        // printf("REM = %lld\n",add);
        cnt[N-1]+=add;
    }
    for(int i = N-1; i; --i)cnt[i-1]+=cnt[i];
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&x);
        printf("%lld\n",cnt[x]);
    }
    return 0;
}