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

int lcs(vector<int> a, vector<int> b){
    vector<vector<int> > dp(a.size()+1,vector<int>(b.size()+1,0));
    for(int i = 0; i <= a.size(); ++i){
        for(int j = 0; j <= b.size(); ++j){
            if(i == 0 || j == 0)dp[i][j] = 0;
            else if(a[i-1] == b[j-1])dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[a.size()][b.size()];
}

void solve(){
    int ans = 0;
    vector<int> arr;
    int a;
    cin >> a;
    if(a){
        arr.pb(a);
        while(1){
            cin >> a;
            if(!a)break;
            arr.pb(a);
        }
    }
    while(1){
        cin >> a;
        if(!a)break;
        vector<int> arr1;
        arr1.pb(a);
        while(1){
            cin >> a;
            if(!a)break;
            arr1.pb(a);
        }
        int l = lcs(arr,arr1);
        ans = max(l,ans);
    }
    cout << ans << "\n";
}

int main(){
    // FILE_READ_IN
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}