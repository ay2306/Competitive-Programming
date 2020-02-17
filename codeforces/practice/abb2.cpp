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
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);


int minimumDays(int rows, int columns, vector<vector<int>> grid){
    multiset<pair<int,pair<int,int>>> m;
    set<pair<int,int>> vis;
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            if(grid[i][j] == 1)m.insert(make_pair(0,make_pair(i,j)));
        }
    }
    int ans = 0;
    if(m.size() == 0)return -1;
    while(m.size()){
        auto u = *m.begin();
        m.erase(m.begin());
        if(vis.find(u.second) != vis.end())continue;
        vis.insert(u.second);
        ans = max(ans,u.first);
        int i = u.second.first;
        int j = u.second.second;
        if(i+1 < rows && vis.find(make_pair(i+1,j)) == vis.end()){
            m.insert(make_pair(u.first+1,make_pair(i+1,j)));
        }
        if(j+1 < columns && vis.find(make_pair(i,j+1)) == vis.end()){
            m.insert(make_pair(u.first+1,make_pair(i,j+1)));
        }
        if(j-1 >= 0 && vis.find(make_pair(1,j-1)) == vis.end()){
            m.insert(make_pair(u.first+1,make_pair(i,j-1)));
        }
        if(i-1 >= 0 && vis.find(make_pair(i-1,j)) == vis.end()){
            m.insert(make_pair(u.first+1,make_pair(i-1,j)));
        }
    }
    return (int)ans;
}
int main(){
    freopen("input.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)cin >> arr[i][j];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << minimumDays(n,m,arr);
   return 0;
}