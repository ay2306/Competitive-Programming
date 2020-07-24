#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> tree;
int n,q,a,b,c;
void update(int idx, int val, int node = 1, int start = 0, int end = n-1){
    if(start == end)return void(tree[node] = val);
    int mid = start + end >> 1;
    idx <= mid ? update(idx,val,node*2,start,mid) : update(idx,val,node*2+1,mid+1,end);
    tree[node] = min(tree[node*2] , tree[node*2 + 1]);
}
int query(int l, int r, int node = 1, int start = 0, int end = n-1){
    if(l > end || r < start) return LLONG_MAX;
    if(l <= start && end <= r)return tree[node];
    int mid = start + end >> 1;
    return min(query(l,r,node*2,start,mid) , query(l,r,node*2+1,mid+1,end));
}

signed main(){
    cin >> n >> q;
    tree = vector<int> (4*n+10,0);
    for(int i = 0; i < n; ++i){
        cin >> a;
        update(i,a);
    }
    while(q--){
        cin >> a >> b >> c;
        if(a == 2)cout << query(b,c-1) << "\n";
        else update(b,c);
    }
    return 0;
}