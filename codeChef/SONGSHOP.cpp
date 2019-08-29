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
struct node{
    ll album;
    ll price;
    ll greatness;
    node(){}
    node(ll a, ll b, ll c):album(a),price(b),greatness(c){}
    bool operator <(node rhs){
        return (album < rhs.album);
    }
};
int main(){
    // FILE_READ_OUT
    FAST
    int n,m,p;
    cin >> n >> m >> p;
    V<node> arr(n+1);
    unordered_map<ll,ll> album_greatness;
    unordered_map<ll,ll> album_price;
    loop(i,1,n+1){
        ll a,b,c;
        // cout << i << ": ";
        cin >> a >> b >> c;
        arr[i] = node(a,b,c);
        album_greatness[a]+=c;
    }
    loop(i,1,m+1){
        ll a;
        cin >> a;
        album_price[i] = a;
    }
    V<bool> albumEnd(n+1,false);
    sort(arr.begin(),arr.end());
    for(int i = 1; i < n; ++i){
        if(arr[i].album != arr[i+1].album)albumEnd[i] = true;
    }
    albumEnd[n] = true;
    ll dp[1002][1002];
    memset(dp,0,sizeof(dp));
    //0-1 Knapsack problem
    int prev_album_end = 0;
    V<int> prev(n+1);
    for(int i = 0; i <= n; ++i){
        prev[i] = prev_album_end;
        if(albumEnd[i])prev_album_end = i;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= p; ++j){
            dp[i][j] = dp[i-1][j];
            if(arr[i].price <= j)dp[i][j] = max(dp[i][j],dp[i-1][j-arr[i].price] + arr[i].greatness);
            if(albumEnd[i]){
                prev_album_end = prev[i];
                if(album_price[arr[i].album] <= j){
                    dp[i][j] = max(dp[i][j], dp[prev_album_end][j-album_price[arr[i].album]] + album_greatness[arr[i].album]);
                }
            }
            // if(j % 5 == 0 && j != 0)printf("\n");
            // printf("dp[%d][%d] = %lld ",i,j,dp[i][j]);
        }
        // printf("\n");
    }
    cout << dp[n][p];
    return 0;
}