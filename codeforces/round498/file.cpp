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
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;
ll a[MAXN][MAXN];
UM<ll,ll> dp[MAXN][MAXN];
ll n,m;
ll k;
ll ans;
int main()
{
    cin >> n >> m >> k;
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
            cin >> a[i][j];
    if(n==1&&m==1)
    {
        if(a[1][1]==k) cout << "1";
        else cout << "0";
        return 0;
    }
    ll lim=(n+m+2)/2;
    dp[1][0][0]=1;
    for(ll i=1;i<=min(n,lim);i++)
    {
        for(ll j=1;i+j<=lim;j++)
        {
            for(auto it=dp[i-1][j].begin();it!=dp[i-1][j].end();it++)
                dp[i][j][(it->F)^a[i][j]]+=it->S;
            for(auto it=dp[i][j-1].begin();it!=dp[i][j-1].end();it++)
               dp[i][j][(it->F)^a[i][j]]+=it->S;
        }
    }
    dp[n][m+1][0]=1;
    ll ans=0;
    for(ll i=n;i>=1;i--)
    {
        for(ll j=m;i+j>lim;j--)
        {
            for(auto it=dp[i+1][j].begin();it!=dp[i+1][j].end();it++)
                dp[i][j][(it->F)^a[i][j]]+=it->S;
            for(auto it=dp[i][j+1].begin();it!=dp[i][j+1].end();it++)
                dp[i][j][(it->F)^a[i][j]]+=it->S;
            if(i+j==lim+1)
            {
                for(auto it=dp[i][j].begin();it!=dp[i][j].end();it++)
                {
                    //printf("%lld %lld %lld\n",i,it->F,it->S);
                    ans+=(it->S)*dp[i-1][j][it->F^k];
                    ans+=(it->S)*dp[i][j-1][it->F^k];
                }
            }
        }
    }
    cout << ans;
    return 0;
}