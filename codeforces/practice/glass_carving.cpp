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
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

int main(){
    FAST
    set<PII> h,w;
    multiset<ll> hl,wl;
    int W,H,n;
    cin >> W >> H >> n;
    h.insert({0,H});
    w.insert({0,W});
    hl.insert(H);
    wl.insert(W);
    while(n--){
        char a;
        int k;
        cin >> a >> k;
        if(a == 'H'){
            auto it = h.lower_bound({k,k});
            it = prev(it);
            ll l = it->second - it->first;
            PII o1 = {it->first,k};
            PII o2 = {k,it->second};
            h.erase(it);
            h.insert(o1);
            h.insert(o2);
            auto jt = hl.find(l);
            hl.erase(jt);
            hl.insert(o1.second - o1.first);
            hl.insert(o2.second - o2.first);
        }else{
            auto it = w.lower_bound({k,k});
            it = prev(it);
            ll l = it->second - it->first;
            PII o1 = {it->first,k};
            PII o2 = {k,it->second};
            w.erase(it);
            w.insert(o1);
            w.insert(o2);
            auto jt = wl.find(l);
            wl.erase(jt);
            wl.insert(o1.second - o1.first);
            wl.insert(o2.second - o2.first);
        }
        cout << *prev(wl.end())*(*(prev(hl.end()))) << "\n";
    }
   return 0;
}