#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
const int mod = 1e9+7;
int n,q,a;

struct SegmentTree{
    int Tree[N<<2];
    SegmentTree(){
        memset(Tree,0,sizeof(Tree));
    }
    void update(int id, int val, int node = 1, int start = 0, int end = n){
        if(start == end)return void(Tree[node] = val);
        int mid = start + end >> 1;
        if(id <= mid)update(id,val,node<<1,start,mid);
        else update(id,val,node<<1|1,mid+1,end);
        Tree[node] = max(Tree[node<<1],Tree[node<<1|1]);
    }
    int query(int l, int r, int node = 1, int start = 0, int end = n){
        if(l > end || r < start)return 0;
        if(l <= start && end <= r)return Tree[node];
        int mid = start + end >> 1;
        return max(query(l,r,node<<1,start,mid),query(l,r,node<<1|1,mid+1,end));
    }
}tree[180];
long long power(long long a, int n){
    if(n == 0)return 1;
    if(n == 1)return a;
    auto p = power(a,n/2);
    p = p * p % mod;
    if(n&1)p = p * a % mod;
    return p;
}

int main(){
    int p[1010] = {0};
    for(int i = 2; i < 1010; ++i){
        if(p[i])continue;
        for(int j = 1; i*j < 1010; ++j)p[i*j]=i;
    }
    vector<int> primes;
    for(int i = 2; i < 1000; ++i)if(p[i] == i)primes.emplace_back(i);
    scanf("%d%d",&n,&q);
    for(int i = 0; i < n; ++i){
        scanf("%d",&a);
        for(int j = 0; j < primes.size(); ++j){
            int cnt = 0;
            while(a && a%primes[j] == 0)a/=primes[j],cnt++;
            if(cnt){
                tree[j].update(i,cnt);
            }
        }
    }
    vector<int> ans(primes.size());
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        long long res = 1;
        for(int j = 0; j < primes.size(); ++j)ans[j] = 0;
        for(int j = 0; j < primes.size(); ++j){
            int pw = tree[j].query(l-1,r-1);
            ans[j] = max(ans[j],pw);
        }
        for(int j = 0; j < primes.size(); ++j){
            // printf("l = %d r = %d prime = %d power = %d\n",l,r,primes[j],ans[j]);
            if(ans[j])res = res * power(primes[j],ans[j]) % mod;
        }
        printf("%lld\n",res);
        // cout << "----------\n";
    }
    return 0;
}