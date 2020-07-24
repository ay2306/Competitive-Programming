#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,tree[N<<2],a[N],ans[N];

void build(int node = 1, int start = 0, int end = n-1){
    if(start == end){
        tree[node] = a[start];
        return;
    }
    int mid = start + end >> 1;
    build(node << 1, start, mid);
    build(node << 1 | 1, mid+1, end);
    tree[node] = tree[node << 1] < tree[node << 1 | 1] ? tree[node << 1] : tree[node << 1 | 1];
}

int query(int l, int r, int mn, int node = 1, int start = 0, int end = n-1){
    if(l > end || r < start)return -1;
    if(l <= start && end <= r){
        if(tree[node] >= mn)return -1;
        while(start != end){
            int mid = start+end >> 1;
            if(tree[node << 1] >= mn){
                start = mid+1;
                node = node << 1 | 1;
            }else{
                end = mid;
                node = node << 1;
            }
        }
        return start;
    }
    int mid = start+end >> 1;
    int p = query(l,r,mn,node<<1,start,mid);
    if(~p)return p;
    return query(l,r,mn,node<<1|1,mid+1,end);
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)scanf("%d",&a[i]);
    reverse(a,a+n);
    build();
    for(int i = 0; i < n; ++i){
        ans[i] = query(0,i,a[i]);
        if(~ans[i])ans[i] = abs(i-ans[i]-1);
    }
    reverse(ans,ans+n);
    for(int i = 0; i < n; ++i)printf("%d ",ans[i]);
    return 0;
}