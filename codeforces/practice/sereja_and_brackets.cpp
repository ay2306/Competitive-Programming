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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

struct Data{
    int open;
    int closed;
    int matched;
    Data(){}
    Data(int o, int c, int m):open(o),closed(c),matched(m){}
};
int n;
V<Data> tree;
string arr;

void build(ll node = 0, ll start = 0, ll end = n-1){
    if(start == end){
        Data res;
        res.open = 0;
        res.closed = 0;
        res.matched = 0;
        if(arr[start] == ')')res.closed = 1;
        else res.open = 1;
        tree[node] = res;
        // printf("For node = %lld, start = %lld, last = %lld, (O, C, M) = (%lld, %lld, %lld) \n",node,start,end,tree[node].open,tree[node].closed, tree[node].matched);
        return;
    }
    build(2*node+1,start,(start+end)/2);
    build(2*node+2,(start+end)/2+1,end);
    tree[node].matched = tree[2*node+1].matched + tree[2*node+2].matched;
    int k = min(tree[2*node+1].open,tree[2*node+2].closed);
    tree[node].matched+=k;
    tree[node].open = tree[2*node+1].open + tree[2*node+2].open;
    tree[node].closed = tree[2*node+1].closed + tree[2*node+2].closed;
    tree[node].closed-=k;
    tree[node].open-=k;
    // printf("For node = %lld, start = %lld, last = %lld, (O, C, M) = (%lld, %lld, %lld) \n",node,start,end,tree[node].open,tree[node].closed, tree[node].matched);
    return;
}

Data query(ll l, ll r, ll node = 0, ll start = 0, ll end = n-1){
    if(start > r || end < l)return Data(0,0,0);
    if(l <= start && end <= r)return tree[node];
    Data a1 = query(l,r, 2*node+1,start,(start+end)/2);
    Data a2 = query(l,r, 2*node+2,(start+end)/2 + 1, end);
    Data res (0,0,0);
    res.matched = a1.matched + a2.matched;
    int k = min(a1.open,a2.closed);
    res.matched+=k;
    res.closed = a1.closed + a2.closed - k;
    res.open = a1.open + a2.open - k;
    return res;
}

int main(){
    FAST
    cin >> arr;
    n = arr.size();
    tree = V<Data> (4*arr.size());
    build();
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        auto res = query(l-1,r-1);
        cout << res.matched*2 << "\n";
    }
    return 0;
}