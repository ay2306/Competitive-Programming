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

ll d(PLL a, PLL b){
    return abs(a.F-b.F)+abs(a.S-b.S);
}

int main(){
    ll x0,y0,ax,ay,bx,by,x,y,t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> x >> y >> t;
    V<PLL> pt;
    while(x0 < 3e16 && y0 < 3e16){
        pt.pb({x0,y0});
        x0 = ax*x0+bx;
        y0 = ay*y0+by;
    }
    int ans = 0;
    loop(i,0,pt.size()){
        loop(j,i,pt.size()){
            int l = j-i+1;
            if(l <= ans)continue;
            ll dist = d(pt[i],pt[j]);
            dist+=min(d(pt[i],{x,y}),d(pt[j],{x,y}));
            if(dist <= t)ans=max(j-i+1,ans);
        }
    }
    cout <<  ans;
   return 0;
}