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

ll ans = 0;
ll dp[100100][2];
void backTracking(int arr[], int n, int i){
    // cout <<g "EHLO";
    if(i >= n){
        ll p = 0;
        for(int j = 1; j < n; ++j)p+=abs(arr[j]-arr[j-1]);
        ans = max(p,ans);
        return ;
    }
    int t = arr[i];
    arr[i] = 1;
    backTracking(arr,n,i+1);
    arr[i] =t;
    backTracking(arr,n,i+1);
}

void solve(){
    ans = 0;
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    long long sum1=0,sum2=0;
    for(int i = 1; i < n; ++i){
        sum1 += abs(arr[i]-arr[i-1]);
    }
    for(int i = 0; i < n; ++i){
        dp[i+1][0] = max(dp[i][0],dp[i][1]+abs(arr[i]-1));
        dp[i+1][1] = max(dp[i][0]+abs(arr[i+1]-1),dp[i][1]+abs(arr[i]-arr[i+1]));
    }
    // for(int i = 1; i < n; ++i){
    //     sum1 += abs(arr[i]-arr[i-1]);
    // }
    cout << max(dp[n-1][1],dp[n-1][0]) << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}