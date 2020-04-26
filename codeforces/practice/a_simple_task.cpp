//https://codeforces.com/contest/558/problem/E
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

template<size_t SZ>
class segmentTree{
    int *tree,*lazy;
public:
    segmentTree(){
        tree = new int[SZ<<2];
        lazy = new int[SZ<<2];
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
    }    
    void update(int l, int r, int val, int node = 1, int start = 0, int end = SZ-1){
        if(lazy[node]){
            (lazy[node] == 1)?tree[node]=(end-start+1):tree[node]=0;
            if(start != end){
                lazy[node<<1] = lazy[node];
                lazy[node<<1|1] = lazy[node];
            }
            lazy[node] = 0;
        }
        if(l > end || r < start)return;
        if(l <= start && end <= r){
            tree[node] = val*(end-start+1);
            (val == 1)?lazy[node]=1:lazy[node]=-1;
            if(start != end){
                lazy[node<<1] = lazy[node];
                lazy[node<<1|1] = lazy[node];
            }
            lazy[node] = 0;
            return;
        }
        int mid = start+end>>1;
        update(l,r,val,node<<1,start,mid);
        update(l,r,val,node<<1|1,mid+1,end);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }
    int query(int l, int r, int node = 1, int start = 0, int end = SZ-1){
        if(lazy[node]){
            (lazy[node] == 1)?tree[node]=(end-start+1):tree[node]=0;
            if(start != end){
                lazy[node<<1] = lazy[node];
                lazy[node<<1|1] = lazy[node];
            }
            lazy[node] = 0;
        }
        if(l > end || r < start)return 0;
        if(l <= start && end <= r)return tree[node];
        int mid = start+end>>1;
        return query(l,r,node<<1,start,mid)+query(l,r,node<<1|1,mid+1,end);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a;
    int l,r,k,n,q,f[26];
    cin >> n >> q >> a;
    segmentTree<N> *s = new segmentTree<N>[26];
    for(int i = 0; i < n; ++i)s[a[i]-'a'].update(i,i,1);
    while(q--){
        cin >> l >> r >> k;
        l--;
        r--;
        for(int i = 0; i < 26; ++i){
            f[i]=s[i].query(l,r);
            s[i].update(l,r,0);
        }
        int st = 0, inc = 1;
        if(!k)st=25,inc=-1;
        for(int i = st; i < 26 && i >= 0 && l <= r; i+=inc){
            if(f[i])s[i].update(l,l+f[i]-1,1);
            l+=f[i];
        }
    }
    for(int i = 0; i < n; ++i)for(int j = 0; j < 26; ++j)if(s[j].query(i,i) == 1)cout << char(j+'a');
    return 0;
}