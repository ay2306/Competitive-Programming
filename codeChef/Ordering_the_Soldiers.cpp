#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+100;
int tree[N<<2];
int n,a;

void update(int idx, int val, int node = 1, int start = 1, int end = n){
    if(start == end)return void(tree[node] = val);
    int mid = start + end >> 1;
    if(idx <= mid)update(idx,val,node<<1,start,mid);
    else update(idx,val,node<<1|1,mid+1,end);
    tree[node] = tree[node<<1]+tree[node<<1|1];
}

int query(int k, int node = 1, int start = 1, int end = n){
    if(start == end)return start;
    int mid = start + end >> 1;
    if(k < tree[node<<1|1])return query(k,node<<1|1,mid+1,end);
    return query(k-tree[node<<1|1],node<<1,start,mid);
}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        fill(tree,tree+(4*n+100),0);
        vector<int> a(n),ans(n);
        for(int &i: a)scanf("%d",&i);
        for(int i = 0; i <= n; ++i)update(i,1);
        for(int i = n-1; ~i ; i--){
            ans[i] = query(a[i]);
            update(ans[i],0);
        }
        for(int i: ans)printf("%d ",i);
        printf("\n");
    }
    return 0;
}