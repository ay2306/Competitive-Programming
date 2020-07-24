#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int on[30][N],msb[30][N],pref[N],arr[N];
void solve(){
    int l,r,n,q;
    scanf("%d%d",&n,&q);
    for(int i = 1; i <= n; ++i){
        scanf("%d",arr+i);
        pref[i] = pref[i-1] + (arr[i] == 0);
        int cur_msb = -1;
        for(int k = 0; k < 30; ++k){
            int b = arr[i] >> k & 1;
            on[k][i] = on[k][i-1] + b;
            if(b)cur_msb = k;
        }
        for(int k = 0; k < 30; ++k){
            msb[k][i] = msb[k][i-1] + (cur_msb == k);
        }
    }
    while(q--){
        scanf("%d%d",&l,&r);
        
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}