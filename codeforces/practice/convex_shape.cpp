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
int n,m;
V<string> arr;
V<V<bool>> visited;

void dfs(int i, int j, int turns, char direction){
    if(i < 0 || j < 0 || i >= n || j >= m)return;
    // if(visited[i][j])return;
    if(turns > 1)return;
    if(arr[i][j] == 'W')return;
    visited[i][j] = true;
    if(direction == 'L')dfs(i,j-1,turns,direction);
    else dfs(i,j-1,turns+1,'L');
    if(direction == 'R')dfs(i,j+1,turns,direction);
    else dfs(i,j+1,turns+1,'R');
    if(direction == 'U')dfs(i-1,j,turns,direction);
    else dfs(i-1,j,turns+1,'U');
    if(direction == 'D')dfs(i+1,j,turns,direction);
    else dfs(i+1,j,turns+1,'D');
}

int main(){
    cin >> n >> m;
    loop(i,0,n){
        string a;
        cin >> a;
        arr.pb(a);
    }
    visited = V<V<bool>> (n,V<bool>(m,false));
    loop(i,0,n){
        loop(j,0,m){
            if(arr[i][j] == 'B'){
                dfs(i,j,-1,' ');
                bool pos = true;
                loop(i1,0,n){
                    loop(j1,0,m){
                        if(arr[i1][j1] == 'B' && !visited[i1][j1])pos = false;
                    }
                }
                if(!pos){
                   // printf("Wrong at i = %d, j = %d\n",i,j);
                    cout << "NO";
                    return 0;
                }
                loop(i1,0,n){
                    loop(j1,0,m){
                        visited[i1][j1] = false;
                    }
                }
            }
        }
    }
    cout << "YES\n";
    return 0;
}
