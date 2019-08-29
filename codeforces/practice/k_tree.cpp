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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;

ull dp[100][2];

int main(){
    int k,n,d;
    bool inc;
    cin >> n >> k >> d;
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i = 1; i <= n; ++i){
        dp[i][0] = dp[i][1] = 0;
        for(int j = 1; j <= k; ++j){
            if(i-j < 0)break;
            if(j < d){
                dp[i][0] = (dp[i][0]%MOD + dp[i-j][0]%MOD)%MOD;
                dp[i][1] = (dp[i][1]%MOD + dp[i-j][1]%MOD)%MOD;
            }else{
                dp[i][1] = (dp[i][1]%MOD + dp[i-j][0]%MOD)%MOD;
                dp[i][1] = (dp[i][1]%MOD + dp[i-j][1]%MOD)%MOD;
            }
        }
    }
    cout << dp[n][1];   
    return 0;
}