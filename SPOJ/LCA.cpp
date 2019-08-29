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
V<V<int> > adj;
V<int> height;
V<int> arr;
V<int> first;
V<int> harr;
V<int> tree;
int n;

void dfs(int s = 0, int p = -1){
    arr.pb(s);
    if(p != -1)height[s] = height[p]+1;
    for(auto i: adj[s]){
        if(i == p)continue;
        dfs(i,s);
        arr.pb(s);
    }
}

void build(int node = 0, int start = 0, int end = arr.size()-1){
    if(start == end){
        tree[node] = start;
        return;
    }
    build(2*node+1,start,(start+end)/2);
    build(2*node+2,(start+end)/2+1,end);
    tree[node] = ((harr[tree[2*node+1]] < harr[tree[2*node+2]])?tree[2*node+1]:tree[2*node+2]);
}

int query(int l, int r, int node = 0, int start = 0, int end = arr.size()-1){
    if(start > r || end < l)return -1;
    int res;
    if(l <= start && end <= r)res = tree[node];
    else{
        int p1 = query(l,r,2*node+1,start,(start+end)/2);
        int p2 = query(l,r,2*node+2,(start+end)/2+1,end);
        if(p1 == -1)res = p2;
        else if(p2 == -1)res = p1;
        else if(harr[p1] < harr[p2])res = p1;
        else res = p2;
    }
    // printf("l = %d, r = %d, node %d, start = %d, end = %d res = %d\n",l,r,node,start,end,res);
    return res;
}

void solve(){
    cin >> n;
    adj = V<V<int> > (n,V<int> ());
    height = V<int> (n,0);
    arr = V<int> ();
    first = V<int> (n,-1);
    loop(i,0,n){
        int a;
        cin >> a;
        loop(j,0,a){
            int k;
            cin >> k;
            k--;
            adj[k].pb(i);
            adj[i].pb(k);
        }
    }
    dfs();
    harr = V<int> (arr.size());
    for(int i = 0; i < arr.size(); ++i){
        if(first[arr[i]] == -1)first[arr[i]] = i;
        harr[i] = height[arr[i]];
    }
    // printf("ARR: ");
    // for(auto i: arr)cout << i+1 << " ";
    // printf("\n");
    // printf("First: ");
    // for(auto i: first)cout << i << " ";
    // printf("\n");
    // printf("Height: ");
    // for(auto i: harr)cout << i << " ";
    // printf("\n");

    tree = V<int> (4*arr.size());
    build();
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        a = first[a-1];
        b = first[b-1];
        if(a > b)swap(a,b);
        int ans = query(a,b);
        // cout << a  << " " << b << " " <<  ans << "\n";
        cout << arr[ans]+1 << "\n";
    }
    
}

int main(){
    int t = 1;
    cin >> t;
    loop(i,1,t+1){
        printf("Case %d:\n",i);
        solve();
    }
    return 0;
}