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

V<string> arr;
int path[1010][1010];
int pos = 0;
int x;
int n,m;

//dp[i][j][k] means maximum start at i,j if taking from maximum from k steps back

int dfs(int i = 0, int j = 0, int k = 0, int ans = 0){
    if(i >= n || j >= m || k > x)return -1;
    // printf("(%d %d %d) -> ",i,j,k);
    if(arr[i][j] == '#')return 0;
    if(arr[i][j] == '*')ans++;
    if(i == n-1 && j == m-1){ 
        return ans;
    }
    int r = dfs(i,j+1,k+1,ans);
    int d = dfs(i+1,j,0,ans);
    return max(r,d);
}


int dfs2(int i = n-1, int j = m-1, int k = 0, int ans = 0){
    if(i < 0 || j < 0 || k > x)return -1;
    // printf("(%d %d %d) -> ",i,j,k);
    if(arr[i][j] == '#')return 0;
    if(arr[i][j] == '*')ans++;
    if(i == 0 && j == 0){ 
        return ans;
    }
    int r = dfs(i,j-1,k+1,ans);
    int d = dfs(i-1,j,0,ans);
    return max(r,d);
}

int main(){
    cin >> n >> m >> x;
    arr = V<string> (n,"");
    loop(i,0,n){
        cin >> arr[i];
    }
    int ans1 = dfs();
    if(ans1 == -1){
        cout << -1;
        return 0;
    }
    int i = 0;
    int j = 0;
    int ans2 = dfs2();
    cout << ans1 << " " << ans2 << "\n";
    if(ans2 > 0){
        ans1+=ans2;
    }
    cout << ans1;
    return 0;
}