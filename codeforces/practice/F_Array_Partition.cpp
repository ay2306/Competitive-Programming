#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
int tree[N*4+100],suff[N],mx,n,arr[N];

void build(int node = 1, int start = 0, int end = n-1){
    if(start == end)return void(tree[node] = arr[start]);
    int mid = start + end >> 1;
    build(node << 1, start, mid);
    build(node << 1 | 1, mid + 1, end);
    tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
}

int query(int l, int r, int node = 1, int start = 0, int end = n-1){
    if( l > end || r < start )return INT_MAX;
    if( l <= start && end <= r)return tree[node];
    int mid = start + end >> 1;
    int p1 = query(l, r, node << 1, start, mid);
    int p2 = query(l, r, node << 1 | 1, mid + 1 ,end);
    return min(p1, p2);
}

void solve(){
    scanf("%d",&n);
    fill(tree,tree+4*n+100,INT_MAX);
    for(int i = 0; i < n; ++i)scanf("%d",arr+i);
    build();
    for(int i = n-1; ~i; --i)suff[i] = max(arr[i], (i+1 < n ? suff[i+1] : INT_MIN));
    for(int i = n-1; ~i; --i)suff[i]*=-1;
    mx = 0;
    for(int i = 0; i+2 < n; ++i){
        mx = max(mx,arr[i]);
        int l = (lower_bound(suff,suff+n,-mx) - suff);
        int r = (upper_bound(suff,suff+n,-mx) - suff) - 1;
        l = max(i+2,l), r = min(r, n-1);
        if(r < l || suff[r] != -mx)continue;
        int lo = l-1, hi = r-1;
        while(lo <= hi){
            int mid = lo + hi >> 1;
            int val = query(i+1,mid);
            if(val == mx){
                printf("YES\n%d %d %d\n",i+1,mid-i,n-1-mid);
                return;
            }
            if(val < mx)hi = mid-1;
            else lo = mid+1;
        }
    }
    printf("NO\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}