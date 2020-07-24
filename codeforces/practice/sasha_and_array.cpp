//https://codeforces.com/problemset/problem/718/C
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define int long long
#define copy(a,b) for(int i = 0; i < N; ++i)for(int j = 0; j < N; ++j)a[i][j] = b[i][j];
using namespace std;
const int N = 2, mod = 1e9+7, M = 1e5+100;
const int m[2][2] = {{1,1},{1,0}};

int ex[40][2][2];


pair<int,int> operator+(const pair<int,int> &a, const pair<int,int> &b){
    pair<int,int> ans((a.first+b.first),(a.second+b.second));
    if(ans.first >= mod)ans.first-=mod;    
    if(ans.second >= mod)ans.second-=mod;    
    return ans;
}

void multiply(int a[2][2],const int b[2][2]){
    int c[2][2];
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            c[i][j] = 0;
            for(int k = 0; k < N; ++k){
                c[i][j] = (c[i][j] + a[i][k]*b[k][j]%mod);
                if(c[i][j] >= mod)c[i][j]-=mod;
            }
        }
    }
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)a[i][j] = c[i][j];
}

void power(int a[N][N], int n){
    int hm[2][2] = {{1,0},{0,1}};
    while(n){
        while(!(n&1))n>>=1,multiply(a,a);
        --n;
        multiply(hm,a);
    }
    copy(a,hm);
}

// void power(int a[N][N], int n){
//     if(n == 0)return;
//     if(n == 1)return;
//     power(a,n/2);
//     multiply(a,a);
//     if(n&1)multiply(a,m);
// }
 

pair<int,int> fib(int n){
    if(n == 1)return pair<int,int> (1,0);
    if(n == 2)return pair<int,int> (1,1);
    int a[2][2] = {{1,1},{1,0}};
    power(a,n-2);
    pair<int,int> ans((a[0][0]+a[0][1]),(a[1][0]+a[1][1]));
    if(ans.first >= mod)ans.first-=mod;
    if(ans.second >= mod)ans.second-=mod;
    return ans; 
}

pair<int,int> tree[M<<2];
int lazy[M<<2], arr[M];
int n,q,a,l,r,x,t;

void build(int node = 1, int start = 1, int end = n){
    if(start == end){
        tree[node] = fib(arr[start]);
        return;
    }
    int mid = start + end >> 1;
    build(node << 1, start, mid);
    build(node << 1 | 1, mid + 1, end);
    tree[node] = (tree[node << 1] + tree[node << 1 | 1]);
}

void update(int l, int r, int x, int node = 1, int start = 1, int end = n){
    if(lazy[node]){
        int a[2][2] = {{1,1},{1,0}};
        power(a,lazy[node]);
        int k1 = (tree[node].first*a[0][0]%mod + tree[node].second*a[0][1]%mod);
        if(k1 >= mod)k1-=mod;
        tree[node].second = (tree[node].first*a[1][0]%mod + tree[node].second*a[1][1]%mod);
        if(tree[node].second >= mod)tree[node].second-=mod;
        tree[node].first = k1;
        if(start != end){
            lazy[node << 1] += lazy[node];
            lazy[node << 1 | 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > end || r < start)return;
    if(l <= start && end <= r){
        int a[2][2] = {{1,1},{1,0}};
        lazy[node] = x;
        power(a,lazy[node]);
        int k1 = (tree[node].first*a[0][0]%mod + tree[node].second*a[0][1]%mod);
        if(k1 >= mod)k1-=mod;
        tree[node].second = (tree[node].first*a[1][0]%mod + tree[node].second*a[1][1]%mod);
        if(tree[node].second >= mod)tree[node].second-=mod;
        tree[node].first = k1;
        if(start != end){
            lazy[node << 1] += lazy[node];
            lazy[node << 1 | 1] += lazy[node];
        }
        lazy[node] = 0;
        return;
    }
    int mid = start + end >> 1;
    update(l,r,x,node << 1, start, mid);
    update(l,r,x,node << 1 | 1, mid + 1, end);
    tree[node] = (tree[node << 1] + tree[node << 1 | 1]);
}

int query(int l, int r, int node = 1, int start = 1, int end = n){
    if(lazy[node]){
        int a[2][2] = {{1,1},{1,0}};
        power(a,lazy[node]);
        int k1 = (tree[node].first*a[0][0]%mod + tree[node].second*a[0][1]%mod);
        if(k1 >= mod)k1-=mod;
        tree[node].second = (tree[node].first*a[1][0]%mod + tree[node].second*a[1][1]%mod);
        if(tree[node].second >= mod)tree[node].second-=mod;
        tree[node].first = k1;
        if(start != end){
            lazy[node << 1] += lazy[node];
            lazy[node << 1 | 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > end || r < start)return 0;
    if(l <= start && end <= r)return tree[node].first;
    int mid = start + end >> 1;
    return query(l,r,node<<1,start,mid)+query(l,r,node<<1|1,mid+1,end);
}

pair<int,int> getTreeNode(int l, int r, int node = 1, int start = 1, int end = n){
    if(l > end || r < start)return pair<int,int> (0,0);
    if(l <= start && end <= r)return tree[node];
    int mid = start + end >> 1;
    return getTreeNode(l,r,node<<1,start,mid)+getTreeNode(l,r,node<<1|1,mid+1,end);
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    copy(ex[0],m);
    for(int k = 1; k < 40; ++k){
        copy(ex[k],ex[k-1]);
        multiply(ex[k],ex[k]);
    }
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)cin >> arr[i];
    build();
    while(q--){
        cin >> t >> l >> r;
        if(t == 2)cout << query(l,r)%mod << "\n";
        else{
            cin >> x;
            update(l,r,x);
        }
    }
    return 0;
}