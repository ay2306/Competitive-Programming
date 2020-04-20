#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
int n,q,x,y,z;
vector<pair<int,int>> nums;
vector<int> tree[4*N],arr;

void build(int node = 1, int start = 1, int end = n){
    if(start == end){
        tree[node].emplace_back(nums[start].second);
        return;
    }
    int mid = start+end >> 1;
    build(node<<1,start,mid);
    build(node<<1|1,mid+1,end);
    merge(tree[node<<1].begin(),tree[node<<1].end(),tree[node<<1|1].begin(),tree[node<<1|1].end(),back_inserter(tree[node]));
    #ifdef LOCAL
    printf("node = %d, Data = ",node);
    for(int &i: tree[node])printf("%d ",i);
    printf("\n");
    #endif
}

int query_kth(int l, int r, int k, int node = 1, int start = 1, int end = n){
    if(start == end)return tree[node][0];
    int mid = start+end>>1;
    auto it = upper_bound(tree[node<<1].begin(),tree[node<<1].end(),r);
    int total = it-lower_bound(tree[node<<1].begin(),tree[node<<1].end(),l);
    if(total >= k)return query_kth(l,r,k,node<<1,start,mid);
    return query_kth(l,r,k-total,node<<1|1,mid+1,end);
}
int main(){
    scanf("%d%d",&n,&q);
    nums.resize(n+1),arr.resize(n+1);
    for(int i = 1; i <= n; ++i)scanf("%d",&arr[i]);
    for(int i = 1; i <= n; ++i)nums[i] = make_pair(arr[i],i);
    sort(nums.begin()+1,nums.end());
    #ifdef LOCAL
    printf("ARRAY = ");
    for(int i = 1; i <= n; ++i)printf(" (%d, %d) ",nums[i].first,nums[i].second);
    printf("\n");
    #endif
    build();
    while(q--){
        scanf("%d%d%d",&x,&y,&z);
        printf("%d\n",arr[query_kth(x,y,z)]);
    }
    return 0;
}