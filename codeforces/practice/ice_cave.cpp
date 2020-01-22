#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
const ll inf = 1e9;
const double pi = acos(-1);
map<PII,PII> parent;
V<string> arr;
V<PII> noted;
int n,m;
int r1,c1,r2,c2;
int vis;

void dfs(int i, int j, PII p){
    if(i < 0 || i >= n || j < 0 || j >= m || arr[i][j] == 'X')return;
    parent[{i,j}] = p;
    arr[i][j] = 'X';
    // cout << i+1 << "  " << j+1 << "\n";
    if(mp(i+1,j) != p)dfs(i+1,j,mp(i,j));
    if(mp(i-1,j) != p)dfs(i-1,j,mp(i,j));
    if(mp(i,j+1) != p)dfs(i,j+1,mp(i,j));
    if(mp(i,j-1) != p)dfs(i,j-1,mp(i,j));
}

int main(){
    cin >> n >> m;
    arr = V<string>(n);
    loop(i,0,n){
        cin >> arr[i];
    }
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    r2--;
    c1--;
    c2--;
    loop(i,0,n)loop(j,0,m)if(arr[i][j] == 'X')noted.pb({i,j});
    if(arr[r2][c2] == 'X'){
        vis++;
    }
    int adj = 0;
    if(r2+1 < n && arr[r2+1][c2] == '.')adj++;
    if(r2-1 >= 0 && arr[r2-1][c2] == '.')adj++;
    if(c2+1 < m && arr[r2][c2+1] == '.')adj++;
    if(c2-1 >= 0 && arr[r2][c2-1] == '.')adj++;
    arr[r1][c1] = '.';
    arr[r2][c2] = '.';
    dfs(r1,c1,{-1,-1});
    if(r1 == r2 && c1 == c2){
        if(adj > 0){
            cout << "YES\n";
            return 0;
        }
    }
    else if(parent.find({r2,c2}) != parent.end()){
        if(abs(r1-r2) + abs(c1-c2) > 1)adj--;
        if(adj > 0 || vis == 1){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
   return 0;
}