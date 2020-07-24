#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

struct Node{
    int val[4],len;
    Node(){
        memset(val,0,sizeof(val));
        len = 0;
    }
};

vector<Node> tree;
int n,m;
string s;
int ch[100];

int choice(int i, int j = -1){
    int res = s[i]-'0';
    if(~j)res = res * 10 + s[j] - '0';
    return ch[res];
}

Node join(Node &left, Node &right, int l, int r){
    Node res;
    int na = left.len == 1 ? 0 : 1;
    int nb = right.len == 1 ? 0 : 2;
    res.len = left.len + right.len;
    res.val[0] = left.val[na] * right.val[nb] % mod;
    res.val[1] = left.val[na] * right.val[3] % mod;
    res.val[2] = left.val[3] * right.val[nb] % mod;
    res.val[3] = left.val[3] * right.val[3] % mod;
    if(s[l] == '1'){
        na = left.len == 1 ? 2 : 0;
        nb = right.len == 1 ? 1 : 0;
        res.val[na+nb] += left.val[0] * right.val[0] % mod * choice(l,r) % mod;
        res.val[na + 1] += left.val[0] * right.val[1] % mod * choice(l,r) % mod;
        res.val[2  + nb] += left.val[2] * right.val[0] % mod * choice(l,r) % mod;
        res.val[3] += left.val[2] * right.val[1] % mod * choice(l,r) % mod;
    }
    for(int i = 0; i < 4; ++i)res.val[i] %= mod;
    return res;
}


void build(int node = 1, int start = 0, int end = n - 1){
    tree[node].len = end - start + 1;
    if(start == end){
        tree[node].val[0] = 1;
        tree[node].val[3] = s[start] - '0' + 1;
        return;
    }
    int mid = start + end >> 1;
    build(node << 1, start, mid);
    build(node << 1 | 1, mid + 1, end);
    tree[node] = join(tree[node << 1], tree[node<<1|1], mid,mid+1);
}

void update(int id, int val, int node = 1, int start = 0, int end = n-1){
    if(start == end){
        s[id] = char(val+'0');
        tree[node].val[3] = val + 1;
        return;
    }
    int mid = start + end >> 1;
    if(id <= mid)update(id,val,node << 1, start, mid);
    else update(id,val,node << 1 | 1, mid + 1, end);
    tree[node] = join(tree[node << 1], tree[node<<1|1], mid,mid+1);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i = 0; i <= 9; ++i){
        for(int j = 0; j <= 9; ++j)ch[i+j]++;
    }
    cin >> n >> m;
    cin >> s;
    tree.resize((n+10)<<2);
    build();
    while(m--){
        int id, x;
        cin >> id >> x;
        id--;
        update(id,x);
        cout << tree[1].val[3] << "\n";
    }
    return 0;
}