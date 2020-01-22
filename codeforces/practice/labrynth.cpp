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
const int N = 3e3+10;
const double pi = acos(-1);
char s[N][N];
int dis[N][N];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int main(){
    int n,m,r,c,x,y;
    cin >> n >> m >> r >> c >> x >> y;
    loop(i,1,n+1){
        scanf("%s",s[i]+1);
    }
    deque<PII> q;
    q.pb({r,c});
    loop(i,0,N)fill(dis[i],dis[i]+N,INT_MAX);
    dis[r][c] = 0;
    int ans = 0;
    while(q.size()){
        int a,b;
        tie(a,b) = q.front();
        q.pop_front();
        // cout << a << " " << b << " " << dis[a][b]   << " " << c+dis[a][b]-b <<  "\n";
        if(dis[a][b] > y)continue;
        if(c + dis[a][b] - b > x)continue;
        ans++;
        loop(i,0,4){
            int tx = a + dx[i];
            int ty = b + dy[i];
            if(tx < 1 || tx > n || ty < 1 || ty > m || s[tx][ty]=='*')continue;
            // cout << tx << " " << ty << " " << dis[tx][ty] << " " << dis[a][b] << "\n";
            if(dis[tx][ty] > dis[a][b] + (i == 0)){
                dis[tx][ty] = dis[a][b] + (i == 0);
                if(i < 2)q.pb({tx,ty});
                else q.push_front({tx,ty});
            }
        }
    }
    cout << ans;
   return 0;
}