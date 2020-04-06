#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int N = 2e5+10;
int tree[N << 2],lazy[N << 2];
int arr[N];
int n;

void build(int node = 0, int start = 0, int end = N-1){
    if(start == end){
        tree[node] = start;
        return;
    }
    int mid = start+end >> 1;
    build(2*node+1,start,mid);
    build(2*node+2,mid+1,end);
    tree[node] = min(tree[2*node+1],tree[2*node+2]);
}

void update(int l, int r, int val, int node = 0, int start = 0, int end = N-1){
    if(lazy[node]){
        tree[node]+=lazy[node];
        if(start != end){
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > end || r < start)return ;
    if(l <= start && end <= r){
        tree[node]+=val;
        if(start != end){
            lazy[2*node+1] += val;
            lazy[2*node+2] += val;
        }
        return;
    }
    int mid = start+end >> 1;
    update(l,r,val,2*node+1,start,mid);
    update(l,r,val,2*node+2,mid+1,end);
    tree[node] = min(tree[2*node+1],tree[2*node+2]);
}

int query(int l, int r, int node = 0, int start = 0, int end = N-1){
    if(lazy[node]){
        tree[node]+=lazy[node];
        if(start != end){
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > end || r < start)return INT_MAX;
    if(l <= start && end <= r)return tree[node];
    int mid = start + end >> 1;
    int p1 = query(l,r,2*node+1,start,mid);
    int p2 = query(l,r,2*node+2,mid+1,end);
    return min(p1,p2);
}

int main(){
    build();
    int n,steps = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)scanf("%d",arr+i);
    for(int i = 1; i <= n; ++i){
        scanf("%d",arr);
        int v = query(arr[0],n);
        printf("MIN INDEX in Range %d-%d = %d\n",arr[0],n,v);
        printf("%d ",arr[v]);
        update(v,n,1);
        // update(v,v,10*n);
        // steps++;
    }
    return 0;
}