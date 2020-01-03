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
const int BIT = 62;
V<int> L,R;
ll dp[70][2][2][2][2];
// * l1 -> 1 means a is strictly greater then L
// * r1 -> 1 means a is strictly less then R
// * l2 -> 1 means b is strictly greater then L
// * r2 -> 1 means b is strictly less then R
ll f(int p = 0, int l1 = 0, int r1 = 0, int l2 = 0, int r2 = 0){
    if(p == int(L.size()))return 0;
    ll &res = dp[p][l1][r1][l2][r2];
    if(res != -1)return res;
    int mn1 = 0, mn2 = 0 ,mx1 = 1, mx2 = 1;
    // * l1 = 0 and L[p] = 1 means that a is less than or equal(not possible) to L and this bit is 1, so we cannot place 0 here.
    if(l1 == 0 && L[p] == 1){
        mn1 = 1;
    }
    // * if a is greater than or equal R and R[p] = 0, then putting 1 here will also increase a to higher value of R
    if(r1 == 0 && R[p] == 0){
        mx1 = 0;
    }
    // * l2 = 0 and L[p] = 1 means that b is less than or equal(not possible) to L and this bit is 1, so we cannot place 0 here.
    if(l2 == 0 && L[p] == 1){
        mn2 = 1;
    }
    // * if b is greater than or equal R and R[p] = 0, then putting 1 here will also increase b to higher value of R
    if(r2 == 0 && R[p] == 0){
        mx2 = 0;
    }
    res = 0;
    loop(i,mn1,mx1+1){
        loop(j,mn2,mx2+1){
            int v = (i^j);
            ll toadd = 0;
            if(v == 1){
                toadd+=(1LL << (int(L.size())-p-1));
            }
            int nl1 = l1;
            int nl2 = l2;
            int nr1 = r1;
            int nr2 = r2;
            if(i > L[p]){
                // * This means that l1 will become greater than L
                nl1 = 1;
            }
            if(i < R[p]){
                // * This means that r1 will become less than R
                nr1 = 1;
            }
            if(j > L[p]){
                // * This means that l2 will become greater than L
                nl2 = 1;
            }
            if(j < R[p]){
                // * This means that r2 will become less than R
                nr2 = 1;
            }
            res = max(res,toadd+f(p+1,nl1,nr1,nl2,nr2));
        }
    }
    return res;
}

int main(){
    ll l,r,temp;
    cin >> l >> r;
    std::memset(dp,-1LL,sizeof(dp));
    temp = l;
    // if(l == r){
    //     cout << 0;
    //     return 0;
    // }
    while(temp){
        L.pb((temp&1));
        temp>>=1;
    }
    temp = r;
    while(temp){
        R.pb((temp&1));
        temp>>=1;
    }
    reverse(all(R));
    while(int(L.size()) < int(R.size()))L.pb(0);
    reverse(all(L));
    cout << f();
   return 0;
}