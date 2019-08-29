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
struct Data{
    int ans;
    int suff;
    int pref;
    int sum;
    Data(int a, int b, int c, int d):pref(a),suff(b),sum(c),ans(d){}
    Data(): pref(0),suff(0),sum(0),ans(0){}
};

int n;
V<Data> tree;
V<int> min_tree;
V<int> tree1;
V<int> arr;

Data make_data(int a){
    return Data(a,a,a,a);
}

Data combine(Data a, Data b){
    Data res;
    res.sum = a.sum+b.sum;
    res.pref = max(a.pref,a.sum+b.pref);
    res.suff = max(b.suff,b.sum+a.suff);
    res.ans = max(max(a.ans,b.ans),a.suff+b.pref);
    return res;
}
void printData(Data a){
    cout << " (" << a.pref << ", " << a.suff << ", " << a.sum << ", " << a.ans << ")  ";
}


void build(int node = 0, int start = 0, int end = n-1){
    if(start == end){
        tree[node] = make_data(arr[end]);
        tree1[node] = arr[end];
        return;
    }
    build(2*node+1,start,(start+end)/2);
    build(2*node+2,(start+end)/2+1,end);
    tree[node] = combine(tree[2*node+1],tree[2*node+2]);
    tree1[node] = max(tree1[2*node+1],tree1[2*node+2]);
}

void update(int l, int r, int val, int node = 0, int start = 0, int end = n-1){
    if(end < l || start > r)return;
    if(l <= start && end <= r){
        tree[node] = make_data(val);
        return;
    }
    update(l,r,val,2*node+1,start,(start+end)/2);
    update(l,r,val,2*node+2,(start+end)/2+1,end);
    tree[node] = combine(tree[2*node+1],tree[2*node+2]);
}



Data query(int l, int r, int node = 0, int start = 0, int end = n-1){
    // if(end < l || start > r)return Data(intONG_MIN/5,intONG_MIN/5,intONG_MIN/5,intONG_MIN/5);
    if(end < l || start > r){
        int a = 0;
        return Data(a,a,a,a);
    }
    if(l <= start && r >= end)return tree[node];
    Data d1 = query(l,r,2*node+1,start,(start+end)/2);
    Data d2 = query(l,r,2*node+2,(start+end)/2+1,end);
    // cout << "For L = " << start << " R = " << end << " Data = " ;
    Data res = combine(d1,d2);
    // printData(res);
    return res;
}

int query1(int l, int r, int node = 0, int start = 0, int end = n-1){
    // if(end < l || start > r)return Data(intONG_MIN/5,intONG_MIN/5,intONG_MIN/5,intONG_MIN/5);
    if(end < l || start > r){
        return INT_MIN;
    }
    if(l <= start && r >= end)return tree1[node];
    int d1 = query1(l,r,2*node+1,start,(start+end)/2);
    int d2 = query1(l,r,2*node+2,(start+end)/2+1,end);
    // cout << "For L = " << start << " R = " << end << " Data = " ;
    // printData(res);
    return max(d1,d2);
}

void solve(){
    cin >> n;
    tree = V<Data> (4*n);
    tree1 = V<int> (4*n);
    arr = V<int> (n);
    loop(i,0,n)cin >> arr[i];
    build();
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        int mx = query1(l-1,r-1);
        if(mx <= 0){
            cout << mx << "\n";
        }else{
            Data res = query(l-1,r-1);
            cout << res.ans << "\n";
        }
    }
}

int main(){
    FAST
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}