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

ll dp[1010][1010];
int arr[1010][1010];
// bool visited[1010][1010];
int n,m;
// ull cal(int i, int j){
//     visited[i][j] = true;
//     if(dp[i][j] > -1)return dp[i][j];
//     ull a,b,c,d;
//     if(arr[i][j] == 1){dp[i][j] = 0;return 0;}
//     if(i+1 <= n && arr[i+1][j] == 1){
//         dp[i][j] = 1;
//         return 1;
//     }
//     if(i-1 > 0 && arr[i-1][j] == 1){
//         dp[i][j] = 1;
//         return 1;
//     }
//     if(j+1 <= m && arr[i][j+1] == 1){
//         dp[i][j] = 1;
//         return 1;
//     }
//     if(j-1 > 0 && arr[i][j-1] == 1){
//         dp[i][j] = 1;
//         return 1;
//     }

//     a =  LLONG_MAX;
//     b =  LLONG_MAX;
//     c =  LLONG_MAX;
//     d =  LLONG_MAX;
//     if(i+1 <= n && !visited[i+1][j]){
//         a = cal(i+1,j);
//     }
//     if(i-1 > 0 && !visited[i-1][j]){
//         b = cal(i-1,j);
//     }
//     if(j+1 <= m && !visited[i][j+1]){
//         c = cal(i,j+1);
//         // return 1;
//     }
//     if(j-1 > 0 && !visited[i][j-1]){
//         d = cal(i,j-1);
//         // return 1;
//     }
//     dp[i][j] = min(a,min(b,min(c,d)));
// }
void solve(){
    bool pos = false;
    V<P<ll,ll> > z,o;
    cin >> n >> m;
    int *row = (int*)calloc(n+1,sizeof(int));
    int *col = (int*)calloc(m+1,sizeof(int));
    for(int i = 1; i <= n; ++i){
        string a;
        cin >> a;
        for(int j = 1; j <= m; ++j){
            arr[i][j] = int(a[j-1]-'0');
            if(arr[i][j] == 1){
                pos = true;
                row[i] = 1;
                col[j] = 1;
            }
       }
    }
    if(!pos){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                cout << "-1 ";
            }
            cout << endl;
        }    
        return;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(col[j] && row[i] && arr[i][j] == 1)cout << "0 ";
            else if(row[i] || col[j])cout << "1 ";
            else cout << "2 ";
        }
        cout << endl;
    }
    
    return ;
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}