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
vector<string> arr;
vector<vector<bool> > visited;
int n,m;
void solve(){
    cin >> n >> m;
    arr = vector<string> (n,"");
    visited = vector<vector<bool> > (n,vector<bool> (m,false));
    loop(i,0,n)cin >> arr[i];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(arr[i][j] == '.' && i+1 < n && arr[i+1][j] == '.' && j+1 < m && arr[i][j+1] == '.' && arr[i+1][j+1] == '.'){
                // printf("(%d,%d)\n",i,j);
                // printf("(%d,%d)\n",i+1,j);
                // printf("(%d,%d)\n",i,j+1);
                // printf("(%d,%d)\n",i+1,j+1);
                visited[i][j] = true;
                visited[i+1][j] = true;
                visited[i][j+1] = true;
                visited[i+1][j+1] = true;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(arr[i][j] == '.' && !visited[i][j]){
                // printf("(%d,%d)\n",i,j);
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main(){
    FAST
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}