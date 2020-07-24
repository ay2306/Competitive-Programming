#include<bits/stdc++.h>
using namespace std;

int a,n;
vector<int> tree;

void update(int idx, int val, int node = 1, int start = 1, int end = n){
    if(start == end){
        tree[node] = 1;
        return;
    }
    int mid = start + end >> 1;
    if(idx <= mid)update(idx,val,node<<1,start,mid);
    else update(idx,val,node<<1|1,mid+1,end);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

int query(int l, int r, int node = 1, int start = 1, int end = n){
    if(l > end || r < start)return 0;
    if(l <= start && end <= r)return tree[node];
    int mid = start + end >> 1;
    return(query(l,r,node<<1,start,mid)+query(l,r,node<<1|1,mid+1,end));
}

int main(){
    scanf("%d",&n);
    tree = vector<int> (n<<2,0);
    for(int i = 0; i < n; ++i){
        scanf("%d",&a);
        printf("%d ",query(a,n));
        update(a,1);
    }
    return 0;
}