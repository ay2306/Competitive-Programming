#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int n,m;
int tree[N],p[N];
vector<int> v[N];
int f(int x){
    if(p[x] <= 0)return x;
    p[x] = f(p[x]);
    return p[x];
}
void u(int a, int b){
    a = f(a),b = f(b);
    if(a==b)return;
    if(p[a] < p[b])swap(a,b);
    p[b]+=p[a];
    p[a] = b;
    for(auto i: v[a]){
        v[b].emplace_back(i);
    }
}

void update(int id, int val, int node = 1, int start = 1, int end = n){
    if(start == end){
        tree[node] =  val;
        return;
    }
    int mid = start + end >> 1;
    if(id <= mid)update(id,val,node<<1,start,mid);
    else update(id,val,node<<1|1,mid+1,end);
    tree[node] = tree[node<<1]+tree[node<<1|1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    memset(tree,0,sizeof(tree));
    memset(p,-1,sizeof(p));
    for(int i = n+1; i < 4*n+100; ++i)p[i] = 0;
    for(int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        int par = a+n;
        p[par]--;
        p[i] = par;
        v[par].emplace_back(i);
    }
    int l = f(1), r;
    for(int i = 2; i <= n; ++i){
        r = f(i);
        if(l != r)update(i,1);
        l = r;
    }

    cout << tree[1] << "\n";
    for(int aa = 1; aa < m; ++aa){
        int a,b;
        cin >> a >> b;
        a+=n;
        b+=n;
        a = f(a);
        b = f(b);
        if(p[a] < p[b])swap(a,b);
        u(a,b);
        for(int i : v[a]){
            int l,r;
            if(i-1){
                l = f(i-1);
                r = f(i);
                if(l!=r)update(i,1);
                else update(i,0);
            }
            if(i+1 <= n){
                l = f(i);
                r = f(i+1);
                if(l!=r)update(i+1,1);
                else update(i+1,0);
            }
        }
        cout << tree[1] << "\n";
    }
    return 0;
}