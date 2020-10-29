#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int tree[N<<2];

void update(int id, int val, int node = 1, int start = 1, int end = N-1){
    if(start == end)return void(tree[node] = val);
    int mid = start + end >> 1;
    if(id <= mid)update(id,val,node<<1,start,mid);
    else update(id,val,node<<1|1,mid+1,end);
    tree[node] = min(tree[node<<1],tree[node<<1|1]);
}

int query(int l, int r, int node = 1, int start = 1, int end = N-1){
    if(l > end || r < start)return INT_MAX;
    if(l <= start && end <= r)return tree[node];
    int mid = start + end >> 1;
    return min(query(l,r,node<<1,start,mid),query(l,r,node<<1|1,mid+1,end));
}

int main(){
    int n,q,a,l,r;
    scanf("%d%d",&n,&q);
    for(int i = 1; i <= n; i++){
        scanf("%d",&a);
        update(i,a);
    }
    while(q--){
        scanf("%d%d",&l,&r);
        printf("%d\n",query(l,r));
    }
    return 0;
}