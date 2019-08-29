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
#define MAXN 25
using namespace std;

V<int> tree;
V<int> lazy;
int n;
void update(ll l, ll r, ll node = 0, ll start = 0, ll end = n-1){
    //this if makes changes if any was due on this segment
    if(lazy[node] != 0){
        tree[node] = end-start+1 - tree[node];
        if(start != end){
            lazy[2*node+1]++ ;
            lazy[2*node+1]%=2 ;
            lazy[2*node+2]++;
            lazy[2*node+2]%=2;
        }
        lazy[node] = 0;
    }
    if(start > r || end < l)return;
    if(start >= l && r >= end){
        //here make changes as per current update
        tree[node] = end-start+1 - tree[node];
        if(start != end){
            lazy[2*node+1]++ ;
            lazy[2*node+1]%=2 ;
            lazy[2*node+2]++;
            lazy[2*node+2]%=2;
        }
        return;
    }
    update(l,r, 2*node+1,start,(start+end)/2);
    update(l,r, 2*node+2,(start+end)/2+1,end);
    tree[node] = tree[2*node+1]+tree[2*node+2];
}

int query(ll l, ll r, ll node = 0, ll start = 0, ll end = n-1){
    if(start > r || end < l)return 0;
    //if changes are due
    if(lazy[node] != 0){
        tree[node] = end-start+1-tree[node];
        if(start != end){
            lazy[2*node+1]++;
            lazy[2*node+2]++;
            lazy[2*node+1]%=2;
            lazy[2*node+2]%=2;
        }
        lazy[node] = 0;
    }
    if(start >= l && end <= r)return tree[node];
    int p1 = query(l,r,2*node+1,start,(start+end)/2);
    int p2 = query(l,r,2*node+2,(start+end)/2 + 1,end);
    return p1+p2;
}

void solve(){
    int q;
    cin >> n >> q;
    tree = V<int> (4*n,0);
    lazy = V<int> (4*n,0);
    while(q--){
        int t,l,r;
        cin >> t >> l >> r;
        if(t == 0){
            update(l,r);
        }else{
            cout << query(l,r) << "\n";
        }
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}