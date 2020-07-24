#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
struct node{
    int cnt[3];
    void rot(){
        int x = cnt[2];
        cnt[2] = cnt[1];
        cnt[1] = cnt[0];
        cnt[0] = x;
    }
    node(){for(int i = 0; i < 3; ++i)cnt[i] = 0;}
    node operator+(const node& rhs){
        node res;
        for(int i = 0; i < 3; ++i)res.cnt[i] = cnt[i] + rhs.cnt[i];
        return res;
    }
};

node tree[N << 2];
int lazy[N << 2],n,q,t,l,r;

void build(int node = 1, int start = 0, int end = n-1){
    if(start == end){
        tree[node].cnt[0]++;
        return ;
    }
    int mid = start + end >> 1;
    build(node<<1,start,mid);
    build(node<<1|1,mid+1,end);
    tree[node] = tree[node<<1]+tree[node<<1|1];
}
void push(int node, int start, int end){
    lazy[node] %= 3;
    for(int i = 0; i < lazy[node]; ++i)tree[node].rot();
    if(start != end)lazy[node<<1] += lazy[node], lazy[node<<1|1] += lazy[node];
    lazy[node] = 0;
}

void update(int l, int r, int node = 1, int start = 0, int end = n-1){
    if(lazy[node])push(node,start,end);
    if(l > end || r < start)return;
    if(l <= start && end <= r){
        lazy[node]++;
        push(node,start,end);
        return;
    }
    int mid = start + end >> 1;
    update(l,r,node<<1,start,mid);
    update(l,r,node<<1|1,mid+1,end);
    tree[node] = tree[node << 1] + tree[node << 1 | 1]; 
}

int query(int l, int r, int node = 1, int start = 0, int end = n-1){
    if(lazy[node])push(node,start,end);
    if(l > end || r < start)return 0;
    if(l <= start && end <= r)return tree[node].cnt[0];
    int mid = start + end >> 1;
    return query(l,r,node<<1,start,mid)+query(l,r,node<<1|1,mid+1,end);
}   

int main(){
    scanf("%d %d",&n,&q);
    build();
    while(q--){
        scanf("%d %d %d",&t,&l,&r);
        if(t == 0)update(l,r);
        else{
            int ans = query(l,r);
            printf("%d\n",ans);
        }
    }
    return 0;
}