#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
int tree[N<<2];

void update(int index, int val, int node = 1, int start = 0, int end = N){
    if(start == end)return void(tree[node]+=val);
    int mid = start + end >> 1;
    if(index <= mid)update(index,val,node<<1,start,mid);
    else update(index,val,node<<1|1,mid+1,end);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}
int query(int l, int r, int node = 1, int start = 0, int end = N){
    if(l > end || r < start)return 0;
    if(l <= start && end <= r)return tree[node];
    int mid = start + end >> 1;
    return query(l,r,node<<1,start,mid) + query(l,r,node<<1|1,mid+1,end);
}

int main(){
    map<char,queue<int>> m;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i)m[s[i]].emplace(i+1);
    vector<int> perm;
    for(int i = n-1; ~i; i--){
        perm.emplace_back(m[s[i]].front());
        m[s[i]].pop();
    }
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        ans+=query(perm[i]+1,n+1);
        update(perm[i],1);
    }
    cout << ans << "\n";
    return 0;
}