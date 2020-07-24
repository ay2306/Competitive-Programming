#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> tree;
int n,q,a,b,c;

void update(int idx, int val, int node = 1, int start = 0, int end = n-1){
    if(start == end)return void(tree[node] = pair<int,int> (val,1));
    int mid = start + end >> 1;
    idx <= mid ? update(idx,val,node*2,start,mid) : update(idx,val,node*2+1,mid+1,end);
    if(tree[node*2].first == tree[node*2+1].first)tree[node] = pair<int,int> (tree[node*2].first,tree[node*2].second+tree[node*2+1].second);
    else tree[node] = min(tree[node*2] , tree[node*2 + 1]);
}

pair<int,int> query(int l, int r, int node = 1, int start = 0, int end = n-1){
    if(l > end || r < start) return pair<int,int>(LLONG_MAX,1);
    if(l <= start && end <= r)return tree[node];
    int mid = start + end >> 1;
    auto left = query(l,r,node*2,start,mid);
    auto right = query(l,r,node*2+1,mid+1,end);
    if(left.first == right.first)return pair<int,int> (left.first,left.second+right.second);
    return min(left,right);
}

signed main(){
    cin >> n >> q;
    tree = vector<pair<int,int>> (4*n+10);
    for(int i = 0; i < n; ++i){
        cin >> a;
        update(i,a);
    }
    while(q--){
        cin >> a >> b >> c;
        if(a == 2){
            auto res = query(b,c-1);
            cout << res.first << " " << res.second << "\n";
        }else update(b,c);
    }
    return 0;
}