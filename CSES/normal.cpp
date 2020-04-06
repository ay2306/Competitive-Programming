#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int N = 2e5+10;
int tree[N << 2];
int arr[N];
int n;

// void build(int node = 0, int start = 0, int end = N-1){
//     if(start == end){
//         tree[node] = start;
//         return;
//     }
//     int mid = start+end >> 1;
//     build(2*node+1,start,mid);
//     build(2*node+2,mid+1,end);
//     tree[node] = min(tree[2*node+1],tree[2*node+2]);
// }

void update(int ind, int node = 0, int start = 0, int end = N-1){
    if(start == end){
        tree[node] = inf;
        return;
    }
    int mid = start+end >> 1;
    if(mid >= ind)update(ind,2*node+1,start,mid);
    else update(ind,2*node+2,mid+1,end);
    tree[node] = min(tree[2*node+1],tree[2*node+2]);
}

int query(int l, int r, int node = 0, int start = 0, int end = N-1){
    if(l > end || r < start)return INT_MAX;
    if(l <= start && end <= r)return tree[node];
    int mid = start + end >> 1;
    int p1 = query(l,r,2*node+1,start,mid);
    int p2 = query(l,r,2*node+2,mid+1,end);
    return min(p1,p2);
}

int main(){
    build();
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)scanf("%d",arr+i);
    for(int i = 1; i <= n; ++i){
        scanf("%d",arr);
        int v = query(arr[0],n);
        printf("%d ",arr[v]);
        update(v);
    }
}