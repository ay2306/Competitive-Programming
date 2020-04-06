#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int SZ = 2e5+10;
int N;
int tree[SZ<<2],arr[SZ],inv[SZ];
int n;
 
void update(int ind, int node = 0, int start = 0, int end = N-1){
    if(start == end){
        tree[node] = 1;
        return;
    }
    int mid = start+end >> 1;
    if(mid >= ind)update(ind,2*node+1,start,mid);
    else update(ind,2*node+2,mid+1,end);
    tree[node] = tree[2*node+1]+tree[2*node+2];
}
 
int query(int l, int r, int node = 0, int start = 0, int end = N-1){
    if(l > end || r < start)return 0;
    if(l <= start && end <= r)return tree[node];
    int mid = start + end >> 1;
    int p1 = query(l,r,2*node+1,start,mid);
    int p2 = query(l,r,2*node+2,mid+1,end);
    return p1+p2;
}
 
int main(){
    int n;
    scanf("%d",&n);
    N = n+1;
    for(int i = 1; i <= n; ++i)scanf("%d",arr+i);
    for(int i = 1; i <= n; ++i){
        scanf("%d",arr);
        int lo = 1;
        int hi = n;
        int ans = 1;
        while(lo <= hi){
            int mi = lo+hi >> 1;
            int del = query(1,mi);
            int actual_index = mi-del;
            if(actual_index == arr[0] && !inv[mi]){
                ans = mi;
                break;
            }else if(actual_index > arr[0]){
                lo = mi+1;
            }else{
                hi = mi-1;
            }
        }
        printf("%d ",arr[ans]);
        inv[ans]=1;
        update(ans);
    }
}