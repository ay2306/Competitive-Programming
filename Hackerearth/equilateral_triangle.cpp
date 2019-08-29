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
ll dp[200][200];
ll C(int n, int r){
    if(r == 0 || r == 1)return 1;
    if(dp[n][r] != 0)return dp[n][r];
    dp[n][r] = C(n-1,r-1) + C(n-1,r);
    return dp[n][r];
}

int main(){
    int n;
    ll ans = 0;
    loop(i,2,n){
        ll k = C(i,2);
        ll rem;
        if(i%2){
            rem = (n+1)/2 + (n+1)%2;
        }else{
            rem = (n+1)/2;
        }
        rem = (i+1)/2 - rem;
        k*=rem;
        ans+=k;
    }
    cout << ans;
  return 0;
}
