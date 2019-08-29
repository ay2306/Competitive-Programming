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
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

int sz;
const int N = 1e6 + 10;
int arr[N];
int freq[N];
struct query{
    int l;
    int r;
    int ind;
};

bool comp(query &x, query &y){
    if(x.l/sz != y.l/sz)return x.l < y.l;
    if((x.l/sz)&1)return x.r < y.r;
    return (x.r > y.r);
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    FAST
    int n;
    cin >> n;
    loop(i,0,n)cin >> arr[i];
    int t;
    cin >> t;
    sz = sqrt(n);
    V<query> q;
    V<int> ans(t);
    loop(i,0,t){
        query a;
        cin >> a.l >> a.r;
        a.l--;
        a.r--;
        a.ind = i;
        q.pb(a);
    }
    sort(all(q),comp);
    int start = 1;
    int end = 0;
    int cnt = 0;
    for(int i = 0; i < q.size(); ++i){
        while(start > q[i].l){
            start--;
            freq[arr[start]]++;
            if(freq[arr[start]] == 1)cnt++;
        }
        while(start < q[i].l){
            freq[arr[start]]--;
            if(freq[arr[start]] == 0)cnt--;
            start++;
        }
        while(end > q[i].r){
            freq[arr[end]]--;
            if(freq[arr[end]] == 0)cnt--;
            end--;
        }
        while(end < q[i].r){
            end++;
            freq[arr[end]]++;
            if(freq[arr[end]] == 1)cnt++;
        }
        ans[q[i].ind] = cnt;
    }
    loop(i,0,t){
        cout << ans[i] << "\n";
    }
    return 0;
}