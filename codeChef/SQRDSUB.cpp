#include<bits/stdc++.h>
#define ll long long int
int main(){
    #ifdef NOT_CODECHEF
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,cnt=0,k,cal=0,prev=0,temp=1,prev_temp=0;
        scanf("%lld",&n);
        for(int i = 0; i < n; ++i){
            scanf("%lld",&k);
            k = abs(k);
            while(k%2 == 0)k/=2,cnt++;
            if(prev==cnt-1){
                prev_temp = temp;
                temp = 0;
            }else if(prev != cnt){
                prev_temp = 0;
                temp = 0;
            }
            temp++;
            cal+=prev_temp;
            prev=cnt;
        }
        printf("%lld\n",(n*(n+1))/2-cal);
    }
    return 0;
}