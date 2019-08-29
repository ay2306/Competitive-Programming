/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
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
#define MAXN 25

using namespace std;
using namespace __gnu_pbds;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n,q;
    cin >> n >> q;
    ll p = 0, id = 0;
    ordered_set<PLL> st;
    unordered_map<ll,vector<ll> > ind;
    loop(i,0,n){
        ll x;
        cin >> x;
        ind[x].pb(id);
        st.insert(mp(x,id++));
    }
    while(q--){
        ll t,a,b,c,d;
        cin >> t >> a >> b >> c >> d;
        ll x = (((p%d * a%d)%d * b%d)%d + c%d)%d;
        if(t == 1){
            ind[x].pb(id);
            st.insert(mp(x,id++));
        }else if(t == 2){
            if(ind[x].size() == 0)continue;
             
        }
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}