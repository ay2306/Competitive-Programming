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
    scanf("%d",&n);
    int ans = 0;
    unordered_map<int,int> freq;
    for(int i = 0; i < n; ++i){
        ll a;
        scanf("%lld",&a);
        if(a > 2*n)ans++;
        else freq[a]++;
    }
    //dp[x][y] means that for y patterns from 1 to x;
    //dp[x][y] = dp[x-1][y] + more x needed
    //dp[x][y] = dp[x-1][y] + abs(y-freq(x))
    // V<V<int> > dp (2*n+1);
    int **dp = new int*[2*n+1];
    dp[0] = (int*)calloc(2*n+1,sizeof(int));
    for(int x = 1; x <= 2*n; ++x){
        int pos_y = 2*n/x;
        dp[x] = (int*)calloc(pos_y+1,sizeof(int));
        for(int y = 0; y <= pos_y; ++y){
            dp[x][y] = dp[x-1][y] + abs(y-freq[x]);
        }
        for(int y = pos_y-1; y >= 0; --y)dp[x][y] = min(dp[x][y],dp[x][y+1]);
    }
    ans = min(n,ans + min(dp[2*n][1],dp[2*n][0]));
    printf("%d\n",ans);
}

int main(){
    // FAST
    int t = 1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}