#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+3;

int tree[N*4 + 100];

void update(int id, int node = 1, int start = 0, int end = N){
    if(start == end)return void(tree[node]++);
    int mid = start + end >> 1;
    if(id <= mid)update(id,node<<1,start,mid);
    else update(id,node<<1|1,mid+1,end);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

int query(int l, int r, int node = 1, int start = 0, int end = N){
    if(l > end || r < start)return 0;
    if(l <= start && end <= r)return tree[node];
    int mid = start + end >> 1;
    return query(l,r,node<<1,start,mid)+query(l,r,node<<1|1,mid+1,end);
}

int main(){
    int mask = 0, bit = 30, n, ans = 0;
    scanf("%d",&n);
    vector<int> a(n),arr(n);
    for(int &i: a)scanf("%d",&i);
    auto countInversion = [&](int mask, int x)->long long{
        memset(tree,0,sizeof(tree));
        long long cnt = 0;
        map<int,int> m;
        for(int i = 0; i < n; ++i)arr[i] = (mask&a[i])^x;
        for(int i = 0; i < n; ++i)m[arr[i]];
        for(auto &i: m)i.second = ++cnt;
        for(int i = 0; i < n; ++i)arr[i] = m[arr[i]];
        cnt = 0;
        for(int i = 0; i < n; ++i){
            cnt += query(arr[i]+1,n+1);
            update(arr[i]);
        }
        return cnt;
    };
    while(~bit){
        mask |= (1LL << bit);
        long long ans1 = countInversion(mask,ans);
        long long ans2 = countInversion(mask,ans^(1LL<<bit));
        if(ans1 > ans2)ans|=(1LL<<bit);
        bit--;
    }
    printf("%lld %d",countInversion(mask,ans),ans);
    return 0;
}