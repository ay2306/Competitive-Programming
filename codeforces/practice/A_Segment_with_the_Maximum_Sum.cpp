#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,id,q,x;

struct segment{
    int sum,pref,suff,ans;
    segment(int val = 0):sum(val),pref(val),suff(val),ans(val){}
};

vector<segment> tree;

void update(int id, int val, int node = 1, int start = 0, int end = n-1){
    if(start == end){
        tree[node] = segment(val);
        return;
    }
    int mid = start + end >> 1;
    if(id <= mid)update(id,val,node<<1,start,mid);
    else update(id,val,node<<1|1,mid+1,end);
    tree[node].sum = tree[node << 1].sum + tree[node << 1 | 1].sum;
    tree[node].pref = max(tree[node<<1].pref,tree[node<<1].sum+tree[node<<1|1].pref);
    tree[node].suff = max(tree[node<<1|1].suff,tree[node<<1|1].sum+tree[node<<1].suff);
    tree[node].ans = max({tree[node<<1].ans,tree[node<<1|1].ans,tree[node<<1].suff+tree[node<<1|1].pref});
}

signed main(){
    cin >> n >> q;
    tree = vector<segment> (n*5);
    for(int i = 0; i < n; ++i){
        cin >> a;
        update(i,a);
    }
    cout << max(0LL,tree[1].ans) << "\n";
    while(q--){
        cin >> id >> x;
        update(id,x);
        cout << max(0LL,tree[1].ans) << "\n";
    }
    return 0;
}