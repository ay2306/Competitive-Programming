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
// Solution based of Dynamic Programming

int main(){
    ll n;
    cin >> n;
    ll dp[4];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for(ll i = 1; i < n; ++i){
        ll a = dp[1]+dp[2]+dp[3];
        ll b = dp[1]+dp[2]+dp[0];
        ll c = dp[1]+dp[3]+dp[0];
        ll d = dp[2]+dp[3]+dp[0];
        dp[0] = a%MOD;
        dp[1] = d%MOD;
        dp[2] = c%MOD;
        dp[3] = b%MOD;
    }
    cout << dp[0];
}


// Solution based on Matrix Exponentiation and Warshall's Algorithm

// vector<vector<ll> > prod(vector<vector<ll> >a, vector<vector<ll> > b){
//     vector<vector<ll> > c = vector<vector<ll> > (4,vector<ll> (4,0));
//     for(int i = 0; i < 4; ++i){
//         for(int j = 0; j < 4; ++j){
//             for(int k = 0; k < 4; ++k){
//                 c[i][j] = ((c[i][j]%MOD)+((a[i][k]%MOD)*(b[k][j]%MOD))%MOD)%MOD;
//             }
//         }
//     }
//     return c;
// }

// vector<vector<ll> > power(vector<vector<ll> >a, ll n){
//     if(n == 1)return a;
//     vector<vector<ll> > c = vector<vector<ll> > (4,vector<ll> (4,0));
//     c = power(a,n/2);
//     c = prod(c,c);
//     if(n%2)c=prod(a,c);
//     return c;
// }

// int main(){
//     ll n;
//     cin >> n;
//     vector<vector<ll> > arr = vector<vector<ll> > (4,vector<ll> (4,1));
//     arr[0][0] = 0;
//     arr[1][1] = 0;
//     arr[2][2] = 0;
//     arr[3][3] = 0;
//     arr = power(arr,n);
//     cout << arr[0][0];
//     return 0;
// }

