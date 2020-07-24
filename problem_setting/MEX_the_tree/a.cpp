#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
pair<int,int> tree[(N<<2)+100];
vector<int> g[N],v[N];
int sub[N],arr[N],ans[N];



void build(int node = 1, int start = 0, int end = N){
    if(start == end){
        tree[node] = pair<int,int> (0,start);
        return;
    }
    int mid = start + end >> 1;
    build(node<<1,start,mid);
    build(node<<1|1,mid+1,end);
    tree[node] = min(tree[node<<1],tree[node<<1|1]);
}

void update(int ind, int val, int node = 1, int start = 0, int end = N){
    if(start == end){
        tree[node].second = start;
        tree[node].first+=val;
        return;
    }
    int mid = start + end >> 1;
    if(ind <= mid)update(ind,val,node<<1,start,mid);
    else update(ind,val,node<<1|1,mid+1,end);
    tree[node] = min(tree[node<<1],tree[node<<1|1]);
}

int calculateSubsize(int u = 1, int p = -1){
    sub[u] = 1;
    for(int &i: g[u]){
        if(i == p)continue;
        sub[u]+=calculateSubsize(i,u);
    }
    return sub[u];
}

void dsu(int u = 1, int p = -1, bool mainChain = true){
    int bigchild = -1, mx = 0;
    for(int i: g[u]){
        if(i == p)continue;
        if(sub[i] > mx)mx=sub[i],bigchild=i;
    }
    for(int i: g[u]){
        if(i == p || i == bigchild)continue;
        dsu(i,u, false);
    }
    if(~bigchild){
        dsu(bigchild,u,true);
        swap(v[u],v[bigchild]);
    }
    for(auto i: g[u]){
        if(i == p || i == bigchild)continue;
        for(int j: v[i])if(arr[j] < N)update(arr[j],1),v[u].emplace_back(j);
    }
    if(arr[u] < N)update(arr[u],1);
    v[u].emplace_back(u);
    ans[u] = tree[1].second;
    if(!mainChain){
        for(int j: v[u])if(arr[j] < N)update(arr[j],-1);
    }
}

int main(){
    build();
    int a,b,n;
    scanf("%d",&n);
    build();
    for(int i = 1; i <= n; ++i)scanf("%d",arr+i);
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    calculateSubsize();
    dsu();
    for(int i = 1; i <= n; ++i)printf("%d\n",ans[i]);
    return 0;
}