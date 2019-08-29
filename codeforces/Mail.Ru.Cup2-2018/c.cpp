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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

struct p{
    ll l,r,t;
};

ll getAns(p a, p b){
    ll g = __gcd(a.t,b.t);
    b.l-=a.l;
    b.r-=a.l;
    a.r-=a.l;
    a.l = 0;
    ll k = b.r;
    k/=g;
    ll br = b.l%g;
    b.r = (b.r-b.l)+br;
    b.l = br;
    ll aa = max(a.l,b.l); 
    ll bb = min(a.r,b.r); 
    ll ans = max(0*1LL,bb-aa+1);
return ans;
}

int main(){
    // FILE_READ_IN
    p a,b;
    cin >> a.l >> a.r >> a.t;
    cin >> b.l >> b.r >> b.t;
    ll ans = getAns(a,b);
    ans = max(ans,getAns(b,a));
    cout << ans;
    return 0;
}