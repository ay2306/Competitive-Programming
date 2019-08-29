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

/*
nCr = n!/(r!(n-r)!)
n-1Cr-1 = (n-1)!/(  x   )
*/

ull dp[100001][2];

ull C(int n, int r){
    if(r == 0 || r == n)return 1;
    if(dp[n][1] != 0 && dp[n][0] != 0)return (dp[n][0] + dp[n][1])%MOD;;
    dp[n][0] = C(n-1,r)%MOD;
    dp[n][1] = C(n-1,r-1)%MOD;
    return (dp[n][0] + dp[n][1])%MOD;
    // return dp[n][r];
}

int main(){
    int n,k,x;
    cin >> n >> k >> x;
    if(k < n-2)cout << "0";
    else cout << C(k,n-2);
    return 0;
}