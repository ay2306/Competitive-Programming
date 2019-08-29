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
const int MAXN = 1e6;
typedef struct segtree{
    ll val;
    bool left,right;
}segtree;

ll arr[MAXN+10];
segtree tree[4*MAXN+10];
ll n,q,l;

void build(int node = 1, int start = 1, int end = n){
    if(start > end)return;
    if(start == end){
        tree[node].val = (arr[start] <= l);
        tree[node].left = (arr[start] <= l);
        tree[node].right = (arr[start] <= l);
        return;
    }
    int mid = (start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node].val = tree[2*node].val + tree[2*node+1].val;
    if(tree[2*node].left && tree[2*node + 1])tree[node].val--;
    tree[node].left = tree[2*node].left; 
    tree[node].right = tree[2*node+1].right; 
}



int main(){
    cin >> n >> q >> l;
    loop(i,1,n+1)cin >> arr[i];
    return 0;
}