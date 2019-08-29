/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;

const ll maxn = 1e5;
const ll inf = 1e9;
V<int> min_tree;
V<int> lazy;
V<int> arr;
unordered_map<int,V<int> > from;
unordered_map<int,V<int> > to;
V<PII> seg;
int n,m;

void build(int node = 0, int start = 0, int end = n-1){
    lazy[node] = 0;
    if(start == end){
        min_tree[node] = arr[start];
        return;
    }
    build(2*node+1,start,(start+end)/2);
    build(2*node+2,(start+end)/2+1,end);
    min_tree[node] = min(min_tree[2*node+1],min_tree[2*node+2]);
}

void update(int l, int r, int val , int node = 0, int start = 0, int end = n-1){
    if(lazy[node] != 0){
        min_tree[node] += lazy[node];
        if(start != end){
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > r || end < l)return;
    // printf("l = %d, r = %d, start = %d, end = %d, node = %  d\n",l,r,start,end,node);
    if(l <= start && end <= r){
        min_tree[node] += val;
        if(start != end){
            lazy[2*node+1] += val;
            lazy[2*node+2] += val;
        }
        return;
    }
    update(l,r,val,2*node+1,start,(start+end)/2);
    update(l,r,val,2*node+2,(start+end)/2+1,end);
    min_tree[node] = min(min_tree[2*node+1],min_tree[2*node+2]);
}

int query(int l, int r, int node = 0, int start= 0, int end = n-1){
    if(lazy[node] != 0){
        min_tree[node] += lazy[node];
        if(start != end){
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > r || end < l)return inf;
    if(l <= start && end <= r){
        return min_tree[node];
    }
    auto p1 = query(l,r,2*node+1,start,(start+end)/2);
    auto p2 = query(l,r,2*node+2,(start+end)/2+1,end);
    return min(p1,p2);
}

int main(){
    FAST
    cin >> n >> m;
    min_tree = V<int> (4*n);
    lazy = V<int> (4*n,0);
    arr = V<int> (n);
    V<int> ans(n);
    unordered_map<int,V<int> > from;
    unordered_map<int,V<int> > to;
    loop(i,0,n){
        cin >> arr[i];
    }
    build();
    loop(i,0,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        from[a].pb(b);
        to[b].pb(a);
        seg.pb(mp(a,b));
    }
    loop(i,0,n){
        ans[i] = arr[i] - min_tree[0];
        int b = i;
        for(int &a : to[i]){
            update(a,b,-1);
        }
    }

    // for(int &i:ans)printf("%d ",i);
    // printf("\n");
    build();
    loopr(i,n-1,0){
        ans[i] = max(arr[i] - min_tree[0],ans[i]);
        int a = i;
        for(int &b : from[i]){
            update(a,b,-1);
        }
    }    
    int idx = max_element(ans.begin(),ans.end()) - ans.begin();
    V<int> aseg;
    for(int k = 0; k < seg.size(); ++k){
        PII &i = seg[k];
        if(i.F <= idx && idx <= i.S)continue;
        aseg.pb(k);
    }
    // for(int &i:ans)printf("%d ",i);
    // printf("\n");
    printf("%d\n%d\n",ans[idx],int(aseg.size()));
    for(int &i:aseg)printf("%d ",i+1);
  return 0;
}