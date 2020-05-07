#include<bits/stdc++.h>
#define ll long long
#define copy(a,b) for(int i = 0; i < 4; ++i)for(int j = 0; j < 4; ++j)a[i][j] = b[i][j];
using namespace std;
const int N = 4;
const ll mod = 1e9+7;
const ll m[4][4] = {{1,1,1,3},{1,0,0,0},{0,0,2,0},{0,0,0,3}};
ll c[4][4],d[4][4];

void mul(ll a[4][4], ll b[4][4]){
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            c[i][j] = 0;
            for(int k = 0; k < 4; ++k)c[i][j] = (c[i][j] + a[i][k]*b[k][j]%mod)%mod;
        }
    }
    copy(a,c);
}

void power(ll a[4][4], ll n){
    if(n == 0)return;
    if(n == 1)return;
    power(a,n>>1);
    copy(d,a);
    mul(a,a);
    if(n&1)mul(a,d);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        if(n <= 1)printf("1\n");
        else{
            ll a[4][4];
            copy(a,m);
            power(a,n-1);
            ll ans = a[0][0]+a[0][1]+2LL*a[0][2]+3LL*a[0][3];
            ans%=mod;
            printf("%lld\n",ans);
        } 
    }
    return 0;
}