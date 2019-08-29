#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x,y,k,n,a,b,pos=0;
    scanf("%d%d%d%d",&x,&y,&k,&n);
    x-=y;
    for(int i = 0; i < n; ++i){
        scanf("%d%d",&a,&b);
        if(a >= x && b <= k){
            pos = 1;
        }
    }
    if(pos)printf("LuckyChef\n");
    if(!pos)printf("UnluckyChef\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}