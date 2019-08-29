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

class Tree{
vector<ll> arr;
vector<ll> tree;
void build(int node, int start, int end){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    build(2*node+1,start,mid);
    build(2*node+2,mid+1,end);
    tree[node] = max(tree[2*node+2],tree[2*node+1]);
}
public:
Tree(vector<ll> arr){
    int n = arr.size();
    this->arr = arr;
    tree = vector<ll>(3*arr.size(),0);
    build(0,0,arr.size()-1);
    // for(auto i : tree){
    //     cout << i << " ";
    // }
    // cout << endl;
}
ll query(int node, int start, int end, int l, int r){
    if(l > end || r < start)return LLONG_MIN;
    if(l <= start && r>= end)return tree[node];
    int mid = (start+end)/2;
    ll p1 = query(2*node+1,start,mid,l,r);
    ll p2 = query(2*node+2,mid+1,end,l,r);
    return max(p1,p2);
}

};

void solve(){
    ll n,q,m;
    cin >> n >> m >> q;
    vector<ll> arr(n,0);
    loop(i,0,n)cin >> arr[i];
    Tree t(arr);
    while(q--){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        // cout << l << " " << r << " " <<  t.query(0,0,n-1,l,r) << endl;
        if(m > 60 && t.query(0,0,n-1,l,r) < m){
            cout << "Happy\n";
        }else{
            cout << "Sad\n";
        }
    }
}

int main(){
    // freopen("input.txt","r",stdin); 
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
