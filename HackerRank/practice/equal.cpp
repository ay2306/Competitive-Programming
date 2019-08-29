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
int dp[1001];
void coin_change(){
    int w[3] = {1,2,5};
    dp[0] = 0;
    for(int i = 1;i <= 1000; ++i){
        int minRes = INT_MAX;
        for(int j = 0; j < 3 && w[j] <= i; ++j){
            int tres = dp[i-w[j]] + 1;
            minRes = min(minRes,tres);
        }
        dp[i] = minRes;
    }
}
void solve(){
    coin_change();
    int n,ans=0;
    cin >> n;
    int MIN = INT_MAX;
    int MAX = INT_MIN;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        MIN  = min(arr[i],MIN);
        MAX = max(MAX,arr[i]);
    }
    int a[1001];
    int ANS = INT_MAX;
    int k = 1;
    while(k <= 3 && MIN >= 0){
        ans = 0;
        for(int i = MIN ; i <= MAX; ++i){
            a[i] = dp[MIN] + dp[i-MIN];
        }
        // cout << MIN << " " << dp[MIN] << endl;
        for(int i = 0; i < n; ++i){
            // if(dp[arr[i]])
            ans+=abs(a[arr[i]]-dp[MIN]);
            // cout << "arr[i] = " << arr[i] << "  a[arr[i]] = " << a[arr[i]] << " ans = " << ans <<  endl;   
        }
        ANS = min(ANS,ans);
        // cout << ans << endl;
        k++;
        MIN--;
    }
    cout << ANS << endl;
}

int main(){
    FILE_READ
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}