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
const int MAX_BIT = 62;
ll dp[63][2][2];
ll dpr[63][2][2];
int *num;
ll count(int pos = 62, int state = 0, int bit = 0){
    if(pos == -1){
        return 1;
    }
    ll &res = dp[pos][state][bit];
    if(dp[pos][state][bit] != -1)return res;
    res = 0;
    int limit = 1;
    if(state == 0){
        limit = num[pos];
    }
    for(int i = 0; i <= limit; ++i){
        if(i == limit && state == 0)res+=count(pos-1,0,i);
        else res+=count(pos-1,1,i);
    }
    return res;
}
int lnum[63];
void setL(ll l){
    ll ind = MAX_BIT;
    while(ind >= 0){
        lnum[ind] = ((l >> ind) & 1);
        ind--;
    }
    num = lnum;
}
int rnum[63];
void setR(ll l){
    ll ind = MAX_BIT;
    while(ind >= 0){
        rnum[ind] = ((l >> ind) & 1);
        ind--;
    }
    num = rnum;
}



void solve(){
    ll ind = MAX_BIT;
    ll l, r, k;
    cin >> l >> r >> k;
    ll ans = 0;
    while(ind >= 0){
        setL(l);
        ll cnt
    }
}

int main(){
   int t = 1;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}