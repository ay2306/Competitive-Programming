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
V<int> arr;

void build(int node, int left, int right){
    if(left == right){
        tree[node] = arr[left];
        return;
    }
    int mid = (left+right)/2;
    build(2*node + 1, left, mid);
    build(2*node + 2, mid+1, right);
    tree[node] = tree[2*node + 1] + tree[2*node + 2];
}

int query(int node, int left, int right, int l, int r){
    if(l > right || r < left)return 0;
    if(left >= l && right <= r)return tree[node];
    int mid = (left + right)/2;
    int p1 = query(2*node + 1, left, mid, l, r);
    int p2 = query(2*node + 2, mid+1, right, l, r);
    return (p1 + p2);
}

void update(int node, int left, int right, int x, int val){
    if(left == right){
        arr[left] = val;
        tree[node] = val;
        return;
    }
    int mid = (left+right)/2;
    if(x > mid){
        update(2*node + 2, mid+1, right, x, val);
    }else{
        update(2*node + 1, left, mid, x, val);
    }
    tree[node] = tree[2*node + 1] + tree[2*node + 2];
}

void solve(){
    int n,q;
    cin >> n >> q;
    V<int> a(n);
    loop(i,0,n)cin >> a[i];
    arr = V<int> (n-1);
    tree = V<int> (4*(n-1));
    for(int i = 0; i < n-1; ++i){
        if(a[i] != a[i+1])arr[i] = 1;
        else arr[i] = 0;
    }
    // for(auto i: arr)cout << i << " ";
    // cout << "\n";
    build(0,0,n-1);
    while(q--){
        int t,l,r;
        cin >> t >> l >> r;
        l--;
        r--;
        if(t == 1){
            update(0,0,n-1,r,(arr[r]^1));
            if(l > 0){
                update(0,0,n-1,l-1,(arr[l-1]^1));
            }
        }else{
            // cout << "L =  " << l << " R = " << r-1 << " ans = ";
            cout << query(0,0,n-1,l,r-1) << "\n";
        }
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}   