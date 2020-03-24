#include <bits/stdc++.h>
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
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
int N;
class GCDTREE{
protected:
    V<int> tree;
public:
    GCDTREE(V<int> &arr){
        N = arr.size();
        tree.resize(N<<2,0);
        build(arr);
    }
    void pull(int node,int start,int end){
        if(start != end)tree[node]=__gcd(tree[node*2+1],tree[node*2+2]);
    }
    void build(V<int> &arr, int node = 0, int start = 0 , int end = N-1){
        if(start == end){
            tree[node] = arr[start];
            return;
        }
        int mid = start+end>>1;
        build(arr,2*node+1,start,mid);
        build(arr,2*node+2,mid+1,end);
        pull(node,start,end);
    }
    int query(int l, int r, int node = 0, int start = 0, int end = N-1){
        if(l > end || r < start)return 0;
        if(l <= start && end <= r)return tree[node];
        int mid = start+end>>1;
        return __gcd(query(l,r,2*node+1,start,mid),query(l,r,2*node+2,mid+1,end));
    }
};

class MIN_TREE{
protected:
    V<pair<int,int>> tree;
public:
    MIN_TREE(V<int> &arr){
        N = arr.size();
        tree.resize(N<<2);
        build(arr);
    }
    void pull(int node,int start,int end){
        if(start != end){
            auto &p = tree[node];
            auto &p1 = tree[2*node+1];
            auto &p2 = tree[2*node+2];
            if(p1.first < p2.first)p = p1;
            else if(p1.first > p2.first)p = p2;
            else p = make_pair(p1.first,p1.second+p2.second);
        }
    }
    void build(V<int> &arr, int node = 0, int start = 0 , int end = N-1){
        if(start == end){
            tree[node] = make_pair(arr[start],1);
            return;
        }
        int mid = start+end>>1;
        build(arr,2*node+1,start,mid);
        build(arr,2*node+2,mid+1,end);
        pull(node,start,end);
    }
    pair<int,int> query(int l, int r, int node = 0, int start = 0, int end = N-1){
        if(l > end || r < start)return make_pair(INT_MAX,0);
        if(l <= start && end <= r)return tree[node];
        int mid = start+end>>1;
        auto p1 = query(l,r,2*node+1,start,mid);
        auto p2 = query(l,r,2*node+2,mid+1,end);
        if(p1.first < p2.first)return p1;
        else if(p1.first > p2.first)return p2;
        return make_pair(p1.first,p1.second+p2.second);
    }
};
int main(){
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(auto &i: arr)scanf("%d",&i);
    MIN_TREE mt(arr);
    GCDTREE gt(arr);
    int q,l,r,g;
    pair<int,int> mn;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        mn = mt.query(l-1,r-1);
        g = gt.query(l-1,r-1);
        if(mn.F == g)printf("%d\n",r-l+1-mn.second);
        else printf("%d\n",r-l+1);
    }
   return 0;
}