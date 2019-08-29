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
int win;
void dfs(int i, int j, char p){
    if(i < 0 || j < 0 || i >= arr.size() || j >= arr.size())return;
    if(arr[i][j] != p)return;
    if(arr[i][j] == 'w' && j == arr.size()-1){
        win = 1;
        return;
    }
    if(arr[i][j] == 'b' && i == arr.size()-1){
        win = 2;
        return;
    }
    if(visited[i][j])return;
    visited[i][j] = true;
    dfs(i-1,j-1,p);
    dfs(i-1,j,p);
    dfs(i,j-1,p);
    dfs(i,j+1,p);
    dfs(i+1,j,p);
    dfs(i+1,j+1,p);
}
int main(){
    // FILE_READ
    FAST
    int k = 1;
    while(1){
        int n;
        cin >> n;
        if(n == 0)break;
        arr.assign(n,"");
        visited.assign(n,vector<bool>(n,false));
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        for(int i = 0; i < n; ++i)if(arr[0][i] == 'b' && !visited[0][i])dfs(0,i,'b');
        for(int i = 0; i < n; ++i)if(arr[i][0] == 'w' && !visited[i][0])dfs(i,0,'w');
        printf("%d %c\n",k++,((win == 1)?'W':'B'));
    }
    return 0;
}