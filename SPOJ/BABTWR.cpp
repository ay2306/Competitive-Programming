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

struct block{
    int height;
    int width;
    int length;
    block(){}
    block(int h,int w,int l):length(l),width(w),height(h){}
    bool operator<(block &rhs){
        return (length < rhs.length && width < rhs.width);
    }
};

bool comp(block a, block b){
    return a.length*a.width <= b.length*b.width;
}

void solve(int n){
    V<block> arr;
    loop(i,0,n){
        int a,b,c;
        cin >> a >> b >> c;
        arr.pb(block(a,b,c));
        arr.pb(block(a,c,b));
        arr.pb(block(b,a,c));
        arr.pb(block(b,c,a));
        arr.pb(block(c,a,b));
        arr.pb(block(c,b,a));
    }
    sort(arr.begin(),arr.end(),comp);
    V<P<block,int> > dp(arr.size());
    V<int> prev(dp.size());
    for(int i = 0; i < arr.size(); ++i){
        dp[i] = mp(arr[i],arr[i].height);
        prev[i] = i;
        for(int j = 0; j < i; ++j){
            if(arr[j] < arr[i]){
                if(dp[i].second < dp[j].second + arr[i].height){
                    dp[i] = mp(arr[i],max(dp[i].second,dp[j].second + arr[i].height));
                    prev[i] = j;
                }
            }
        }
    }
    int ans = 0;
    int ansi = 0;
    for(int i = 0; i < dp.size(); ++i){
        if(ans < dp[i].second){
            ans = max(ans,dp[i].second);
            ansi = i;
        }
    
    }
    while(1){
        // printf("(%d, %d, %d) -> ",dp[ansi].first.length,dp[ansi].first.width,dp[ansi].first.height);
        if(ansi == prev[ansi])break;
        ansi = prev[ansi];
    }
    // cout << "\n";
    cout << ans << "\n";
}

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0)break;
        solve(n);
    }
    return 0;
}