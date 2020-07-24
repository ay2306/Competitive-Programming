#include<bits/stdc++.h>
using namespace std;

int a,n;
vector<int> tree;


void update(int id, int val, int node = 1, int start = 1, int end = n){
    if(start == end){
        tree[node] = val;
        return;
    }
    int mid = start + end >> 1;
    if(id <= mid)update(id,val,node<<1,start,mid);
    else update(id,val,node<<1|1,mid+1,end);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}
 
int query(int k, int node = 1, int start = 1, int end = n){
    if(start == end)return start;
    int mid = start + end >> 1;
    if(tree[node << 1 | 1] >= k)return query(k,node<<1|1,mid+1,end);
    return query(k-tree[node<<1|1],node<<1,start,mid);
}
 

int main(){
    scanf("%d",&n);
    tree = vector<int> (n<<2,0);
    vector<int> arr(n);
    for(int i = 1; i <= n; ++i){
        scanf("%d",&arr[i-1]);
        update(i,1);
    }
    for(int i = n-1; i >= 0; --i){
        int res = query(arr[i]+1);
        update(res,0);
        arr[i] = res;
    }
    for(int i: arr)printf("%d ",i);
    return 0;
}