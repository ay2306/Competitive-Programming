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
using namespace std;

const ll maxn = 1e5;
int n,m,k;
V<string> arr;
V<V<bool> > visited;
bool valid(int i, int j){
    if(i >= 0 && i < n && j >= 0 && j < m)return true;
    return false;
}

void dfs(int i, int j){
    if(visited[i][j])return;
    visited[i][j] = true;
    if(arr[i][j] != '.')return;
    if(valid(i+1,j))dfs(i+1,j);
    if(valid(i-1,j))dfs(i-1,j);
    if(valid(i,j+1))dfs(i,j+1);
    if(valid(i,j-1))dfs(i,j-1);
    if(k > 0){
        arr[i][j] = 'X';
        k--;
    }
}

int main(){
    cin >> n >> m >> k;
    arr = V<string> (n,"");
    visited = V<V<bool> > (n, V<bool>(m,false));
    loop(i,0,n){
        cin >> arr[i];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(arr[i][j] != '#' && !visited[i][j]){
                dfs(i,j);
            }
        }
    }
    for(auto i: arr){
        cout << i << "\n";
    }
    return 0;
}