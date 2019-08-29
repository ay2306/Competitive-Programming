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

V<int> num;
ll dp[20][2][10];

ll cal(int pos, int f, int first, int last){
    if(pos == num.size()){
        if(first == last && first != 0)return 1;
        return 0;
    }
    if(dp[pos][f][first] != 0)return dp[pos][f][first];
    int lt;
    if(f){
        lt = 9;
    }else{
        lt = num[pos];
    }
    ll res = 0;
    for(int i = 0; i <= lt; ++i){
        if(first == 0){
            first = i;
        }
        if(i == lt && f == 0)res+=cal(pos+1,0,first,i);
        else res+=cal(pos+1,1,first,i);
    }
    dp[pos][f][first] = res;
    return dp[pos][f][first];
}

ll calfi(ll a){
    num = V<int> ();
    while(a){
        num.pb(a%10);
        a/=10;
    }
    reverse(num.begin(),num.end());
    memset(dp,0,sizeof(dp));
    return cal(0,0,0,0);
}

void solve(){
    ll l,r;
    cin >> l >> r;
    ll k = 0;
    ll ans = 0;
    // ll c = (l != 1)?1:0;
    // if(l > 10)k = 0;
    // else if( r > 10)k = 9-l + c;
    // else{
    //     k = r-l -c;
    // }
    l--;
    ll s1 = 0;
    ll s2 = 0;
    if(l > 0){
        s1 = calfi(l);
    }
    
    s2 = calfi(r);
    cout << s1 << " " << s2 << "\n";
    ans += s2 - s1 ;
    for(ll i = 1; i < 10; ++i){
        if(i >=l && i <=r)ans++;
    }
    cout << ans;
}

int main(){
    FILE_READ_OUT
    for(int i = 1; i < 100; ++i){
        cout << i << " = " << calfi(i*1LL) << "\n";
    }
    // int t = 1;
    // // cin >> t;
    // while(t--)solve();
    return 0;
}