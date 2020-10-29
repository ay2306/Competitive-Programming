#include<bits/stdc++.h>
#define int unsigned
using namespace std;
const int N = 1e5+10;

int tree[N<<2],arr[N];
int n;

void build(int node = 1, int start = 0, int end = n-1){
    if(start == end){
        tree[node] = arr[start];
        return ;
    }
    int mid = start + end >> 1;
    build(node << 1, start, mid);
    build(node << 1 | 1, mid + 1, end);
    tree[node] = tree[node<<1]&tree[node<<1|1];
}

int query(int l, int r, int node = 1, int start = 0, int end = n-1){
    if(l > end || r < start)return INT_MAX;
    if(l <= start && end <= r)return tree[node];
    int mid = start + end >> 1;
    int p1 = query(l,r,node << 1, start, mid);
    int p2 = query(l,r,node << 1 | 1, mid + 1, end);
    return (p1&p2);
}

signed main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)scanf("%d",arr+i);
    build();
    int q,l,r,s,t;
    scanf("%d",&q);
    scanf("%d",&t);
    while(q--){
        scanf("%d%d%d%d",&l,&r,&s,&t);
        l--,r--;
        int ans = 0;
        for(int i = l; i + s - 1 <= r; ++i){
			ans+=(query(i,i+s-1) >= t);
        }
        printf("%d\n",ans);
    }
    return 0;
}