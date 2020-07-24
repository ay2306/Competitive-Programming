#include<bits/stdc++.h>
using namespace std;

vector<int> tree;
int n,m,t,x,l;

void update(int id, int val, int node = 1, int start = 0, int end = n-1){
    if(start == end){
        tree[node] = val;
        return;
    }
    int mid = start + end >> 1;
    if(id <= mid)update(id,val,node<<1,start,mid);
    else update(id,val,node<<1|1,mid+1,end);
    tree[node] = max(tree[node<<1] , tree[node<<1|1]);
}

int query(int x, int node = 1, int start = 0, int end = n-1){
    if(start == end)return start;
    int mid = start + end >> 1;
    if(tree[node << 1] >= x)return query(x,node<<1,start,mid);
    return query(x,node<<1|1,mid+1,end);
}

int main(){
    scanf("%d%d",&n,&m);
    tree = vector<int> ((n+10)<<2,0);
    for(int i = 0; i < n; ++i){
        scanf("%d",&x);
        update(i,x);  
    }
    while(m--){
        scanf("%d",&t);
        if(t == 1){
            scanf("%d%d",&l,&x);
            update(l,x);
        }
        else{
            scanf("%d",&x);
            if(tree[1] < x)printf("-1\n");
            else printf("%d\n",query(x));
        } 
    }
    return 0;
}