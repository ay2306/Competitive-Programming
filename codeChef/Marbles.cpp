#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
    Think like this
    we take first k marbles and put them of different colors
    Now we need to place remaining n-k ( lets call it T )
    in k boxes (colors)
    Formula for that is C(T+k-1,k-1) = C(n-k+k-1,k-1)
                        = C(n-1,k-1) = (n-1)!/(n-k)!(k-1)!;
*/


int32_t main(){
    int n,k,t;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        int ans = 1 , cnt = min(n-k,k-1);
        for(int i = 1; i <= cnt; ++i){
            ans *= (--n);
            ans /= i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}