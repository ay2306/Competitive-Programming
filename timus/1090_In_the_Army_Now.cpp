#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10;

int tree[N<<2], n, arr[N], check[N];

void update(int id, int val, int node = 1, int start = 0, int end = n){
    if(start == end)return void(tree[node]++);
    int mid = start + end >> 1;
    if(id <= mid)update(id,val,node<<1,start,mid);
    else update(id,val,node<<1|1,mid+1,end);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

int query(int l, int r, int node = 1, int start = 0, int end = n){
    if(l > end || r < start) return 0;
    if(l <= start && end <= r)return tree[node];
    int mid = start + end >> 1;
    return query(l,r,node<<1,start,mid) + query(l,r,node<<1|1,mid+1,end);
}

int main(){
    int k;
    cin >> n >> k;
    int mx = -1, ans = 0;
    for(int index = 1; index <= k; ++index){
        fill(tree,tree + 4*(n+10),0);
        for(int i = n-1; ~i; --i)cin >> arr[i];
        for(int i = 0; i < n; ++i)check[i] = arr[i];
        sort(check,check+n);
        for(int i = 0; i < n; ++i)arr[i] = lower_bound(check,check+n,arr[i]) - check;
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            cnt+=query(0,arr[i]);
            update(arr[i],1);
        }
        if(cnt > mx)mx = cnt,ans = index;
    }
    cout << ans;
    return 0;
}