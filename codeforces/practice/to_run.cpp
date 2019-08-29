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
#define MAXN 5000100
using namespace std;

ll dp[MAXN];
ll sum[MAXN];
int v[MAXN];
void solve(){
    int a,b;
    cin >> a >> b;
    ll n = sum[a];
    ll k = sum[b];
    // for(int i = b+1; i<=a; ++i)cout << sum[i] << " ";
    // cout << endl;
    cout << n-k << endl;
}

int main(){
    for(int i = 2; i < MAXN; ++i)if(v[i] == 0)for(int j = 2; i*j < MAXN; ++j){
        v[i*j]++;
        ll k = 1LL*i*j;
        while(k%i == 0){
            dp[i*j]++;
            k/=i;
        }
    }
    dp[1] = 0;
    for(int i = 2; i < MAXN; ++i){
        if(v[i] == 0){
            dp[i]=1;
            sum[i] = sum[i-1]+(dp[i]);
        }
        else sum[i] = sum[i-1]+(dp[i]);
    }
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}