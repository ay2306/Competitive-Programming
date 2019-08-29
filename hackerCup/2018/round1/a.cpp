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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output1.txt","w",stdout);
#define MAXN 25
using namespace std;

ull dp[5][1010];
char arr[5][1010];
ll ne,me;

ull numberOfPaths(int n, int m, char d){
    if(n == 4 )
    return dp[m][n];
}

int main(){
    FILE_READ
    int t;
    cin >> t;
    for(int l = 1; l <= t ;l++){
        int n,m;
        cin >> m;
        n = 3;
        me = m;
        ne = 4;
        for(int i = 1; i <= n; ++i){
            string a;
            cin >> a;
            for(int j = 1; j <= m; ++j){
                arr[i][j] = a[j-1];
                dp[i][j] = 0;
            }
        }
        cout << "Case #" << l << ": ";
        cout << numberOfPaths(1,1,1,0) << endl;
    }
    return 0;
}