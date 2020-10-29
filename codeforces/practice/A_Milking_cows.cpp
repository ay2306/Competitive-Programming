#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct segment{
    vector<int> lazy;
    vector<pair<int,int>> tree;
    segment(){
        tree = vector<pair<int,int>> (n*4 + 10);
        lazy = vector<int> (n*4 + 10,0);
        build();
    }
    void build(int node = 1, int start = 1, int end = n){
        if(start == end)return void(tree[node] = make_pair(INT_MAX,start));
        int mid = start + end >> 1;
        build(node<<1,start,mid);
        build(node<<1|1,mid+1,end);
        tree[node] = min(tree[node<<1],tree[node<<1|1]);
    }
    void update(int l, int r, int val, int node = 1, int start = 1, int end = n){
        if(lazy[node]){
            tree[node].first+=lazy[node];
            if(start != end){
                lazy[node<<1]+=lazy[node];
                lazy[node<<1|1]+=lazy[node];
            }
            lazy[node] = 0;
        }
        if(l > end || r < start)return;
        if(l <= start && end <= r){
            tree[node].first += val;
            if(start != end){
                  lazy[node<<1]+=val;
                lazy[node<<1|1]+=val;
            }
            return;
        }
        int mid = start + end >> 1;
        update(l,r,val,node<<1,start,mid);
        update(l,r,val,node<<1|1,mid+1,end);
        tree[node] = min(tree[node<<1],tree[node<<1|1]);
    }
    pair<int,int> query(int l, int r, int node = 1, int start = 1, int end = n){
        if(lazy[node]){
            tree[node].first+=lazy[node];
            if(start != end){
                lazy[node<<1]+=lazy[node];
                lazy[node<<1|1]+=lazy[node];
            }
            lazy[node] = 0;
        }
        // cout << l << " " << r << " " << start << " " << end << "\n";
        if(l > end || r < start)return make_pair(INT_MAX,1);
        if(l <= start && end <= r)return tree[node];
        int mid = start + end >> 1;
        auto p1 = query(l,r,node<<1,start,mid);
        auto p2 = query(l,r,node<<1|1,mid+1,end);
        return min(p1,p2);
    }
};

signed main(){
    cin >> n;
    vector<int> arr(n+1),c(n+1);
    for(int i = 1; i <= n; ++i)cin >> arr[i];
    segment tree;
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        c[i]+=cnt;
        cnt+=arr[i];
        cout << c[i] << " ";
    }
    cout << endl;
    cnt = 0;
    for(int i = n; i; --i){
        c[i]+=cnt;
        cnt+=!arr[i];
        int val = tree.query(i,i).first;
        tree.update(i,i,c[i]-val);
        cout << tree.query(i,i).first << " ";
    }
    int ans = 0;
    for(int step = 0; step < n; ++step){
        auto res = tree.query(1,n);
        cout << res.first << " " << res.second << "\n";
        ans+=res.first;
        tree.update(res.second,res.second,INT_MAX);
        if(arr[res.second])tree.update(res.second,n,-1);
        else tree.update(1,res.second,-1);
    }
    cout << ans;
    return 0;
}