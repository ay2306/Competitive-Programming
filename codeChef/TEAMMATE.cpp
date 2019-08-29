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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;
ll dp[1000100];

ll calPossiblePairs(ll n){
    if(n < 3)return 1LL;
    if(dp[n] != 0)return dp[n];
    dp[n] = ((n*(n-1)/2)%MOD * calPossiblePairs(n-2)%MOD)%MOD;
    return dp[n];
}
void solve(){
    unordered_map<ll,int> m;
    int n;
    ll ans = 1;
    cin >> n;
    set<ll,greater<ll> > arr;
    for(int i = 0; i < n; ++i){
        ll a;
        cin >> a;
        m[a]++;
        arr.insert(a);
    }
    // cout << "ARR: ";
    // for(auto i: arr){
    //     cout << i << " ";
    // }
    // cout << "\n";
    if(arr.size() == 1){
        cout << calPossiblePairs(m[*arr.begin()])%MOD << "\n";
        return ;
    }
    ll last = 0;
    for(auto i : arr){
        // cout << "For i = " << i << "  m[i] = " << m[i] << "\n";
        if(last == 1){
            // cout << "Call at" << "A\n";
            ans = (ans%MOD * (m[i] % MOD))%MOD;
            m[i]--;
        }
        last = (m[i]%2);
        if(m[i]){
            // cout << "Call at" << "B\n";
            ans = (ans%MOD * calPossiblePairs(m[i])%MOD)%MOD;
        }
    }
    cout << ans << "\n"; 
}

int main(){
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 3;
    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << calPossiblePairs(n) << "\n";
    }
    // solve();
    return 0;
}