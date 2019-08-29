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
using namespace std;

const ll maxn = 1e5;
// ll dp[102][102][2710];
V<V<V<int> > > dp;
int main(){
    // freopen("input.txt","w",stdout);
    // cout << "200 200\n";
    // for(int i = 0; i < 200; ++i){
    //     cout << "1000000000000000000 ";
    // }
    // FILE_READ_IN
    // FILE_READ_OUT
    dp = V<V<V<int> > > (40,V<V<int> > (202, V<int> (5410,-100000000)));
    int n,k;
    cin >> n >> k;
    V<int> pw2(n+1,0);
    //pw2 will store maximal power of 2 for ith number;
    V<int> pw5(n+1,0);
    //pw5 will store maximal power of 5 for ith number;
    loop(i,1,n+1){
        ll a;
        cin >> a;
        while(a && a%2 == 0){
            pw2[i]++;
            a/=2;
        }
        while(a && a%5 == 0){
            pw5[i]++;
            a/=5;
        }
        // printf("(%d, %d)  ", pw2[i],pw5[i]);
    }
    // dp[i][j][l] store the maximum number of power of 2 I can get till i by choosing j element if maximum l number of power of 5s are allowed 
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= k; ++j){
            for(int l = 0; l < 5410; ++l){
                dp[(i + 30)%30][j][l] = dp[(i + 30 - 1)%30][j][l];
                if(j > 0 && pw5[i] <= l){
                    if(dp[(i + 30 - 1)%30][j-1][l-pw5[i]] >= 0){
                        dp[(i + 30)%30][j][l] = max(dp[(i + 30)%30][j][l],dp[(i - 1 + 30)%30][j-1][l-pw5[i]] + pw2[i]);
                    }
                }
            }
        }
    }
    // for(int l = 0; l <= 4; ++l){
    //     printf("l == %d\n",l);
    //     for(int i = 0; i <= n; ++i){
    //         for(int j = 0; j <= k; ++j){
    //             printf("(%d, %d, %lld)\t",i,j,((dp[i][j][l] >= 0)?(dp[i][j][l]):-1*1LL));
    //         }
    //         printf("\n");
    //     }
    //     printf("\n");
    // }
    int ans = 0;
    for(int j = 0; j < 5410; ++j){
        ans = max(ans,min(dp[n%30][k][j],j));
    }
    // freopen ("/dev/tty", "a", stdout);
    cout << ans;
    return 0;
}