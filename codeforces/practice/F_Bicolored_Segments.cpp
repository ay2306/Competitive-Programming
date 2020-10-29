#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

vector<int> tree[2],lazy[2];
const int N = 4e5+10;
vector<pair<int,int>> v[N];
void build(vector<int> &tree, int node = 1, int start = 0, int end = N-1){
    if(start == end){
        return ;
    }
    int mid = start + end >> 1;
    build(tree, node << 1 , start, mid);
    build(tree, node << 1 | 1, mid + 1, end);
    tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
}

void push(int index, int node, int start, int end){
    tree[index][node] += lazy[index][node];
    if(start != end){
        lazy[index][node << 1] += lazy[index][node];
        lazy[index][node << 1 | 1] += lazy[index][node];
    }
    lazy[index][node] = 0;
}

void update(int index, int l, int r, int val, int node = 1, int start = 0, int end = N-1){
    if(lazy[index][node])push(index,node,start,end);
    if( l > end || r < start )return;
    if( l <= start && end <= r ){
        lazy[index][node] += val;
        push(index, node, start, end);
        return ;
    }
    int mid = start + end >> 1;
    update(index, l, r, val, node << 1, start, mid);
    update(index, l, r, val, node << 1 | 1, mid + 1, end);
    tree[index][node] = max ( tree[index][node << 1], tree[index][node << 1 | 1] );
}

int query(int index, int l, int r, int node = 1, int start = 0, int end = N-1){
    if(lazy[index][node])push(index,node,start,end);
    if( l > end || r < start )return INT_MIN;
    if( l <= start && end <= r )return tree[index][node];
    int mid = start + end >> 1;
    int p1 = query ( index, l, r, node << 1, start, mid );
    int p2 = query ( index, l, r, node << 1 | 1, mid + 1, end );
    return max ( p1, p2 );
}
int main(){
    int n,t,l,r,stamp = 0;
    scanf("%d",&n);
    vector<pair<pair<int,int>,int>> a;
    map<int,int> m;
    for(int i = 0; i < n; ++i){
        scanf("%d%d%d",&l,&r,&t);
        a.emplace_back(make_pair(l,r),t);
        m[l],m[r];
    }
    for(auto &i: m)i.y=++stamp;
    for(auto &i: a){
        i.x.x = m[i.x.x];
        i.x.y = m[i.x.y];
        v[i.x.y].emplace_back(i.x.x,i.y);
    }
    int ans = 0;
    for(int j = 0; j < 2; ++j){
        lazy[j] = vector<int> (N << 2, 0);
        tree[j] = vector<int> (N << 2, 0);
    }
    for(int i = 1; i <= stamp; ++i){
        for(auto &j: v[i])
            update(j.y-1,0,j.x-1,1);
        int res = 0;
        for(int j = 0; j < 2; ++j)res = max(res,query(j,0,i-1));
        for(int j = 0; j < 2; ++j)
            update(j,i,i,res);
        ans = max(ans,res);
    }
    printf("%d",ans);
    return 0;
}