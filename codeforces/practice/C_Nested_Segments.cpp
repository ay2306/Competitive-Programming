#include<bits/stdc++.h>
using namespace std;

vector<int> tree;
int n,x;

void update(int id, int node = 1, int start = 1, int end = 2*n){
    if(start == end)return void(tree[node] = 1);
    int mid = start + end >> 1;
    if(id <= mid)update(id,node<<1,start,mid);
    else update(id,node<<1|1,mid+1,end);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

int query(int l, int r, int node = 1, int start = 1, int end = 2*n){
    if(l > end || r < start)return 0;
    if(l <= start && end <= r)return tree[node];
    int mid = start + end >> 1;
    return query(l,r,node<<1,start,mid) + query(l,r,node<<1|1,mid+1,end);
}

int main(){
    scanf("%d",&n);
    vector<pair<int,int>> a(n+1,make_pair(0,0));
    vector<int> arr((n<<1)+10),ans(n+10);
    for(int i = 1; i <= 2*n; ++i){
        scanf("%d",&x);
        arr[i] = x;
        if(!a[x].first)a[x-1].second = i;
        else a[x-1].first = i;
    }
    sort(a.begin(),a.end());
    tree = vector<int> (n<<3,0);
    
    for(auto i: a){
        if(i.first == 0)continue;
        ans[arr[i.first]] = query(i.second,2*n);
        update(i.second);
    }

    for(int i = 1; i <= n; ++i)printf("%d ",ans[i]);
    return 0;
}