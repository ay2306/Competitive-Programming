/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/

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

string printBinary(ll a){
    string ans = "";
    while(a){
        if(a % 2)ans+="1";
        else ans+="0";
        a/=2;
    }
    reverse(all(ans));
    return ans;
}

void vispres(ll l, ll r){
    while(l <= r){
        cout << l << " : " << printBinary(l) << "\n";
        l++;
    }
}

void solve(){
    ll l,r,l1,r1;
    cin >> l >> r;
    ll ans = (r*(r+1))/2 - ((l*(l-1)))/2;
    ll ct = 0;
    ll ind = 0;
    l1=l;
    r1=r;
    // vispres(l,r);
    // printf("init = %lld\n",ans);
    do{
        ct = ((r >> ind) / 2) + ( (r >> ind) % 2) - (((l-1) >> ind) / 2) - (((l-1) >> ind) % 2);
        ans-=ct*(1LL << ind);
        // printf("ind = %lld, power = %lld, ct = %lld, sub = %lld, ans = %lld\n",ind,(1LL<<ind),ct,ct*(1LL<<ind),ans);
        ind++;
    }while((1LL << ind) < inf);
    ind = 0;
    while((1LL << ind) < inf){
        ll val = (1LL << ind);
        if(val >= l1 && val <= r1)ans--;
        ind++;
    }
    ind = 0;
    cout << ans << "\n";
}

int main(){
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}