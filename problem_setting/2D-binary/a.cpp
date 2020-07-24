#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+1;

bitset<N> s[N],aux;
int ans = 0;
int n,q,t,l,r;
int main(){
    scanf("%d%d",&n,&q);
    for(int i = 1; i <= n; ++i)aux[i] = 1;
    while(q--){
        scanf("%d",&t);
        if(t == 1){
            printf("%d\n",ans);
        }else if(t == 2){
            scanf("%d%d",&l,&r);
            ans -= s[l].count();
            s[l][r] = 1 - s[l][r];
            ans += s[l].count();
        }else{
            scanf("%d",&l);
            ans -= s[l].count();
            s[l] = ~s[l];
            s[l] &= aux;
            ans += s[l].count();
        }
    }
    return 0;
}