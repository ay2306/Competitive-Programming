#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
const ll maxn = 1e5;
const ll inf = 1e15;
const double pi = acos(-1);
int N;
class SegmentTree{
    vector<PLL> tree;
    vector<ll> lazy;
public:
    SegmentTree(vector<ll> &arr){
        N = arr.size();
        tree.resize(N << 2);
        lazy.resize(N << 2);
        build(arr);
    }
    void pull(int node, int start, int end){
        if(start != end){
            if(tree[2*node+1].first < tree[2*node+2].first)tree[node]=tree[2*node+1];
            else if(tree[2*node+1].first > tree[2*node+2].first)tree[node]=tree[2*node+2];
            else if(tree[2*node+1].second > tree[2*node+2].second)tree[node]=tree[2*node+1];
            else if(tree[2*node+1].second < tree[2*node+2].second)tree[node]=tree[2*node+2];
        }
    }
    void push(int node, int start, int end){
        tree[node].first-=lazy[node];
        if(start != end){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node] = 0;
    }
    void build(vector<ll> &arr, int node = 0, int start = 0, int end = N-1){
        if(start == end){
            tree[node] = make_pair(arr[start],start);
            return ;
        }
        int mid = start+end>>1;
        build(arr,2*node+1,start,mid);
        build(arr,2*node+2,mid+1,end);
        pull(node,start,end);
    }
    void update(int l, int r, ll val, int node = 0, int start = 0, int end = N-1){
        if(lazy[node]!=0)push(node,start,end);
        if(l > end || r < start)return;
        if(l <= start && end <= r){
            lazy[node]+=val;
            push(node,start,end);
            return;
        }
        int mid = start+end>>1;
        update(l,r,val,2*node+1,start,mid);
        update(l,r,val,2*node+2,mid+1,end);
        pull(node,start,end);
    }
    pair<ll,ll> query(int l, int r, int node = 0, int start = 0, int end = N-1){
        if(lazy[node]!=0)push(node,start,end);
        if(l > end || r < start)return make_pair(LLONG_MAX,LLONG_MAX);
        if(l <= start && end <= r){
            return tree[node];
        }
        int mid = start+end>>1;
        auto p1 = query(l,r,2*node+1,start,mid);
        auto p2 = query(l,r,2*node+2,mid+1,end);
        if(p1.first  < p2.first)return p1;
        else if(p1.first  > p2.first)return p2;
        else if(p1.second > p2.second)return p1;
        return p2;   
    }
};

int main(){
    int n;
    scanf("%d",&n);
    V<ll> a(n),ans(n);
    for(auto &i: a)scanf("%lld",&i);
    SegmentTree s(a);
    loop(i,1,n+1){
        auto j = s.query(0,n-1);
        ans[j.second] = i;
        s.update(j.second,n-1,i);
        s.update(j.second,j.second,-inf);
    }
    for(auto &i: ans)printf("%lld ",i);
   return 0;
}