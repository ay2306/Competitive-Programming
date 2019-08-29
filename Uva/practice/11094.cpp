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
#define MAXN 1001000
using namespace std;

vector<string> arr;
vector<vector<bool>> visited;
int n,m;
int x[4] = {-1,1,0,0};
int y[4] = {0,0,1,-1};


void dfsKing(int i, int j,char p){
    if(i == -1){
        i = n-1;
    }
    if(i == n){
        i = 0;
    }
    if(j == -1){
        j = m-1;
    }
    if(j == m){
        j = 0;
    }
    if(arr[i][j] != p)return;
    if(visited[i][j])return;
    visited[i][j] = true;
    for(int k = 0; k < 4; ++k)dfsKing(i+x[k],j+y[k],p);
}

int dfs(int i, int j, char p){
    if(i == -1){
        i = n-1;
    }
    if(i == n){
        i = 0;
    }
    if(j == -1){
        j = m-1;
    }
    if(j == m){
        j = 0;
    }
    if(arr[i][j] != p)return 0;
    if(visited[i][j])return 0;
    visited[i][j] = true;
    int ans = 1;
    for(int k = 0; k < 4; ++k)ans+=dfs(i+x[k],j+y[k],p);
    return ans;
}

int main(){
    FILE_READ
    cin >> n >> m;
    while(1){
        arr = vector<string>();
        visited = vector<vector<bool> > (n,vector<bool>(m,false));      
        for(int i = 0; i < n; ++i){
            string a;
            cin >> a;
            arr.pb(a);
        }
        int x,y;
        cin >> x >> y;
        char t = arr[x][y];
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; ++j){
        //         if(arr[i][j] == t)arr[i][j] = 'l';
        //         else arr[i][j] = 'w';
        //     }
        // }
        dfsKing(x,y,arr[x][y]);
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!visited[i][j] && arr[i][j] == arr[x][y])ans = max(ans,dfs(i,j,arr[i][j]));
            }
        }
        cout << ans << "\n";
        if(cin >> n >> m){}
        else break;
    }
    return 0;
}