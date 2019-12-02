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
using namespace std;
// For ordered_set
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
V<int> arr;
V<int> prv;
V<int> nxt;
V<int> tree;
int n;
int sz;
void build(int node = 0, int start = 0, int end = sz-1){
    if(start == end){
        tree[node] = start;
        return;
    }
    build(2*node+1,start,((start+end) >> 1));
    build(2*node+2,((start+end) >> 1)+1,end);
    if(arr[tree[2*node+1]] < arr[tree[2*node+2]]){
        tree[node] = tree[2*node+1];
    }else{
        tree[node] = tree[2*node+2];
    }
}
int query(int l, int r, int node = 0, int start = 0, int end = sz-1){
    if(start > r || end < l)return -1;
    // cout << start << " --||--  " << end << "\n";
    if(l <= start && end <= r)return tree[node];
    int p1 = query(l,r,2*node+1,start,((start+end) >> 1));
    int p2 = query(l,r,2*node+2,((start+end) >> 1)+1,end);
    if(p1 == -1)return p2;
    if(p2 == -1)return p1;
    return (arr[p1] < arr[p2])?p1:p2;
}

// int d = 0;
int find_answer(int l, int r, int convertValue){
    // d++;
    // cout << l << " " << r << "\n";
    // if(d > 10)return 0;
    if(l > r || l < 0 || r >= sz)return 0;
    int r1 = query(l,r);
    // cout << "r1 = " << r1 << "  mn = " << convertValue << "\n";
    if(l == r)return convertValue != arr[l];
    int mn = r1;
    int l1 = prv[r1];
    int ans = 0;
    while(l1 >= l){
        ans+=find_answer(l1+1,r1-1,arr[mn]);
        r1 = l1;
        l1 = prv[r1];
    }
    if(r1 != l)ans+=find_answer(l,r1-1,arr[mn]);
    l1 = query(l,r);
    r1 = nxt[l1];
    while(r1 <= r && r1 >= 0){
        // d++;
        ans+=find_answer(l1+1,r1-1,arr[mn]);
        l1 = r1;
        r1 = nxt[l1];
    }
    if(l1 != r)ans+=find_answer(l1+1,r,arr[mn]);
    if(arr[mn] != convertValue)ans++;
    // printf("arr[mn] = %d, converValue = %d, ans = %d\n",arr[mn],convertValue,ans);
    // d--;
    return ans;
}
void solve(){
    cin >> n;
    arr = V<int> (1);
    cin >> arr[0];
    unordered_map<int,int> p,nx;
    loop(i,1,n){
        int a;
        cin >> a;
        if(a != arr.back())arr.pb(a);
    }
    sz = arr.size();
    n = arr.size();
    tree = V<int> (4*n);
    build();
    prv = V<int> (sz,-1);
    nxt = V<int> (sz,-1);
    loop(i,0,n){
        if(p.find(arr[i]) == p.end()){
            p[arr[i]] = i;
        }else{
            prv[i] = p[arr[i]];
            p[arr[i]] = i;
        }
    }
    loopr(i,n-1,0){
        if(nx.find(arr[i]) == nx.end()){
            nx[arr[i]] = i;
        }else{
            nxt[i] = nx[arr[i]];
            nx[arr[i]] = i;
        }
    }
    cout << find_answer(0,n-1,arr[query(0,sz-1)]) << "\n";
}

int main(){
    FAST
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}