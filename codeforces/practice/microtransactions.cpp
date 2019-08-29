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
#define ord_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
const ll maxn = 1e9;
const ll N = 4e5;
int n,m;
V<ll> req;
V<PLL> dis;

bool check(ll c){
    //lst[i] here shows the last day when ith item had a discount
    V<ll> lst(n,-1);
    loop(i,0,m){
        if(dis[i].F <= c){
            lst[dis[i].S] = max(lst[dis[i].S],dis[i].F);
        }
    }
    //off[i] stores the set of items which have their last discount of ith day
    V<V<ll>> off(c+1,V<ll>());
    loop(i,0,n){
        if(lst[i] != -1){
            off[lst[i]].pb(i);
        }
    }
    //need[i] stores required items for of ith type
    V<ll> need = req;
    ll cur = 0;
    loop(i,0,c+1){
        //We earn 1 coin
        ++cur;
        //iterating over all the items which have last discount this day
        for(auto it : off[i]){
            //if I can buy these items
            if(cur >= need[it]){
                cur-=need[it];
                need[it] = 0;
            }else{
            // I cannot buy items anymore
                need[it] -= cur;
                cur = 0;
                break;
            }
        }
    }
    return accumulate(all(need),0*1LL) * 2 <= cur;
}

int main(){
    cin >> n >> m;
    req = V<ll> (n);
    dis = V<PLL> (m);
    loop(i,0,n){
        cin >> req[i];
    }
    loop(i,0,m){
        cin >> dis[i].F >> dis[i].S;
        dis[i].F--;
        dis[i].S--;
    }
    ll high = N;
    ll low = 0;
    ll ans = high;
    while(low <= high){
        ll mid = (low+high)/2;
        if(check(mid)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout << ans+1;
  return 0;
}
