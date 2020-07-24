#include<bits/stdc++.h>
using namespace std;

vector<int> tree;
int n,m,t,x;

void update(int id, int node = 1, int start = 0, int end = n-1){
    if(start == end){
        tree[node] ^= 1;
        return;
    }
    int mid = start + end >> 1;
    if(id <= mid)update(id,node<<1,start,mid);
    else update(id,node<<1|1,mid+1,end);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

int query(int k, int node = 1, int start = 0, int end = n-1){
    if(start == end)return start;
    int mid = start + end >> 1;
    if(tree[node << 1] >= k)return query(k,node<<1,start,mid);
    return query(k-tree[node<<1],node<<1|1,mid+1,end);
}

int main(){
    scanf("%d%d",&n,&m);
    tree = vector<int> ((n+10)<<2,0);
    for(int i = 0; i < n; ++i){
        scanf("%d",&x);
        if(x)update(i);  
    }
    while(m--){
        scanf("%d%d",&t,&x);
        if(t == 1)update(x,1);
        else printf("%d\n",query(x+1));
    }
    return 0;
}