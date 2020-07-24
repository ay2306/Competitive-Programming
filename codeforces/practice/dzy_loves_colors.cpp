//https://codeforces.com/contest/444/problem/C
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5;
class SegmentTree{
    int *tree,*lazy;
public:
    SegmentTree(){
        tree = (int*)calloc(N+10<<2,sizeof(int));
        lazy = (int*)calloc(N+10<<2,sizeof(int));
    }
    void push(int node, int start, int end){
        tree[node] += (end-start+1)*lazy[node];
        if(start != end){
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
        lazy[node] = 0;
    }
    void update(int l, int r, int val, int node = 1, int start = 1, int end = N){
        if(!lazy[node])push(node,start,end);
        if(l > end || r < start)return;
        if(l <= start && end <= r){
            lazy[node]+=val;
            push(node,start,end);
            return;
        }
        int mid = start + end >> 1;
        update(l,r,val,node<<1,start,mid);
        update(l,r,val,node<<1|1,mid+1,end);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }
    int query(int l, int r, int node = 1, int start = 1, int end = N){
        if(!lazy[node])push(node,start,end);
        if(l > end || r < start)return 0;
        if(l <= start && end <= r)return tree[node];
        int mid = start + end >> 1;
        return query(l,r,node<<1,start,mid) + query(l,r,node<<1|1,mid+1,end);
    }
}sumTree;

class ColorSegmentTree{
    int *tree,*lazy;
public:
    ColorSegmentTree(){
        tree = (int*)calloc(N+10<<2,sizeof(int));
        lazy = (int*)calloc(N+10<<2,sizeof(int));
        build();
    }
    void build(int node = 1, int start = 1, int end = N){
        lazy[node] = 0;
        if(start == end){
            tree[node] = start;
            // if(end <= 5)printf("start = %lld, end = %lld, tree[node] = %lld\n",start,end,tree[node]);
            return;
        }
        int mid = start + end >> 1;
        build(node << 1, start, mid);
        build(node << 1 | 1, mid+1, end);
        if(tree[node<<1] == tree[node<<1|1])tree[node] = tree[node<<1];
        else tree[node] = -1;
        // if(end <= 5)printf("start = %lld, end = %lld, tree[node] = %lld\n",start,end,tree[node]);
    }
    void push(int node, int start, int end){
        tree[node] = lazy[node];
        // if(end <= 5)printf("LAZY, start = %lld, end = %lld, tree[node] = %lld\n",start,end,tree[node]);
        if(start != end){
            lazy[node<<1] = lazy[node];
            lazy[node<<1|1] = lazy[node];
        }
        lazy[node] = 0;
    }
    void update(int l, int r, int val, int node = 1, int start = 1, int end = N){
        if(lazy[node])push(node,start,end);
        if(l > end || r < start)return;
        if(l <= start && end <= r && ~tree[node]){
            sumTree.update(start,end,abs(tree[node]-val));
            // printf("CALL start = %lld, end = %lld, val = %lld, tree[node] = %lld\n",start,end,abs(tree[node]-val),tree[node]);
            lazy[node]=val;
            push(node,start,end);
            return;
        }
        int mid = start + end >> 1;
        update(l,r,val,node<<1,start,mid);
        update(l,r,val,node<<1|1,mid+1,end);
        if(tree[node<<1] == tree[node<<1|1])tree[node] = tree[node<<1];
        else tree[node] = -1;
        // tree[node] = ~tree[node<<1] && tree[node<<1] == tree[node<<1|1] ? tree[node << 1] : -1;
    }
}colorTree;

int32_t main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t,l,r,x,n,q;
    cin >> n >> q;
    while(q--){
        cin >> t >> l >> r;
        if(t == 1){
            cin >> x;
            colorTree.update(l,r,x);
        }else{
            cout << sumTree.query(l,r) << "\n";
        }
    }
    return 0;
}