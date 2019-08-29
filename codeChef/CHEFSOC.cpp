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

void solve(){
    int n;
    cin >> n;
    V<int> arr(n+10);
    loop(i,0,n)cin >> arr[i];
    V<ll> dp(n+10,0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1 + ((arr[0] == 2)?1:0);
    for(int i = 3; i < n; ++i){
        dp[i] = dp[i-1] + ((arr[i-2] == 2)?1:0)*dp[i-2] + ((arr[i-3] == 2 && arr[i-2] == 2)?1:0)*dp[i-3];
        dp[i]%=MOD;
    }
    V<int> pos(n);
    stack<int> s;
    for(int i  = 0; i < n; ++i){
        if(arr[i] == 1){
            while(s.size()){
                pos[s.top()] = i;
                s.pop();
            }
        }
        s.push(i);
    }
    while(s.size()){
        pos[s.top()] = -1;
        s.pop();
    }
    ll ans = 1;
    for(int i = 1; i < n; ++i){
        if(arr[i-1] == 2){
            ll x = pos[i] - i;
            if(x%2 == 1 && pos[i] != -1){
                if(pos[i] != n-1 && arr[pos[i] + 1] == 2){
                    x++;
                }
            }else if(pos[i]!=-1){
                x--;
            }else{
                x = n-1-i;
            }
            // cout << i << " " << x << " " << pos[i] << "\n";
            ans = ans%MOD + (x%MOD*dp[i-1]%MOD)%MOD;
        }
        ans+=dp[i];
        ans%=MOD;
    }
    cout << ans << "\n";
}

int main(){
    // FILE_READ_OUT
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}