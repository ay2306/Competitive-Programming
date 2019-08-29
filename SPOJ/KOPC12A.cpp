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

V<ll> h;
V<ll> cost;
int n;

ll cst(ll a){
    ll ans = 0;
    loop(i,0,n){
        ans+=(cost[i]*abs(a-h[i]));
    }
    return ans;
}

void solve(){
    cin >> n;
    h = V<ll> (n);
    cost = V<ll> (n);
    loop(i,0,n)cin >> h[i];
    loop(i,0,n)cin >> cost[i];
    ll low = 0;
    ll ans = LLONG_MAX;
    ll high = *max_element(h.begin(),h.end());
    // loop(i,low,high+1){
    //     cout << cst(i) << " ";
    // }
    //     cout << "\n";
    while(high-low >= 3){
        ll m1 = low + (high-low)/3;
        ll m2 = high - (high-low)/3;
        ll s1 = cst(m1);
        ll s2 = cst(m2);
        // cout << low << " " << high << " " << m1 << " " << s1  << " " << m2 << " " << s2 << endl;
        if(s1 < s2){
            ans = min(ans,s1);
            high = m2;
        }else{
            ans = min(ans,s2);
            low = m1;
        }
    }
    ans = min(cst(low+1),ans);
    ans = min(cst(low+2),ans);
    cout << ans << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}