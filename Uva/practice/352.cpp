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
vector<vector<bool> > visited;
void dfs(int i, int j){
    if(i < 0 || j < 0 || i >= arr.size() || j >= arr.size())return;
    if(visited[i][j])return;
    if(arr[i][j] == '0')return;
    visited[i][j] = true;
    int x[] = {-1,-1,-1,0,0,1,1,1};
    int y[] = {-1,0,1,-1,1,-1,0,1};
    for(int k = 0; k < 8; ++k)dfs(i+x[k],j+y[k]);
}
int main(){
    // FILE_READ
    FAST
    int n,c = 1;
    cin >> n;
    while(1){
        arr.assign(n,"");
        visited.assign(n,vector<bool>(n,false));
        int ans = 0;
        for(int i = 0; i < n; ++i)cin >> arr[i];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(arr[i][j] == '1' && !visited[i][j]){
                    ans++;
                    dfs(i,j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",c++,ans);
        if(cin >> n){

        }else{
            break;
        }
    }
    return 0;
}