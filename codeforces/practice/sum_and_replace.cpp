#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 3e5+10;

ll n,t,l,r,a,q,d[N],pr[N << 2],sum[N << 2],f[N<<2],arr[N];
short processed[N<<2];

int getFactorCount(int a){
    if(f[a] != 0)return f[a];
    int d = 1, k =a;
    int p = -1, cnt = 1;
    while(a > 1){
        if(pr[a] != p)d*=cnt,cnt=1;
        cnt++;
        p = pr[a];
        a/=pr[a];
    }
    d*=cnt;
    f[k] = d;
    return f[k];
}

void build(int node = 0, int start = 0, int end = n-1){
    if(start == end){
        sum[node] = arr[start];
        processed[node] = (sum[node] <= 2);
        return;
    }
    build(2*node+1,start,(start+end>>1));
    build(2*node+2,(start+end>>1)+1,end);
    processed[node] = processed[2*node+1]&&processed[2*node+2];
    sum[node] = sum[2*node+1]+sum[2*node+2];
}

void update(int l, int r, int node = 0, int start = 0, int end = n-1){
    if(l > end || r < start || processed[node])return;
    if(start == end){
        sum[node] = getFactorCount(sum[node]);
        if(sum[node] <= 2)processed[node] = true;
        return;
    }
    update(l,r,2*node+1,start,(start+end>>1));
    update(l,r,2*node+2,(start+end>>1)+1,end);
    processed[node] = processed[2*node+1]&&processed[2*node+2];
    sum[node] = sum[2*node+1]+sum[2*node+2];
}

ll getSum(int l, int r, int node = 0, int start = 0, int end = n-1){
    if(l > end || r < start)return 0;
    if(l <= start && end <= r)return sum[node];
    return getSum(l,r,2*node+1,start,(start+end>>1))+getSum(l,r,2*node+2,(start+end>>1)+1,end);
}
 

int main(){
    for(int i = 2; i <= int(1e6); ++i){
        if(pr[i])continue;
        for(int j = i; j <= int(1e6); j+=i)pr[j]=i;
    }
    scanf("%d%d",&n,&q);
    for(int i = 0; i < n; ++i){
        scanf("%d",arr+i);
    }
    build();
    while(q--){
        scanf("%d%d%d",&t,&l,&r);
        l--,r--;
        if(t == 1)update(l,r);
        else printf("%lld\n",getSum(l,r));
    }
    return 0;
}