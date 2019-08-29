#include <stdio.h>

void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    // cin >> n >> m;
    int arr[1000];
    int mx = -1;
    int i;
    for(int i = 0; i < n; ++i){
        scanf("%d",arr+i);
        if(mx < arr[i])mx = arr[i];
    }
    int req = 0;
    for(int i = 0; i < n; ++i){
        req+=(mx-arr[i]);
    }
    if(req > m){
        printf("No\n");
    }else{
        m-=req;
        if(m%n == 0)printf("Yes\n");
        else printf("No\n");
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}