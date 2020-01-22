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
ll a[4][4];
ll ans[1010][1010];
int main(){
    int n;
    cin >> n;
    a[0][0] = 8;
    a[0][1] = 9;
    a[0][2] = 1;
    a[0][3] = 13;
    a[1][0] = 3;
    a[1][1] = 12;
    a[1][2] = 7;
    a[1][3] = 5;
    a[2][0] = 0;
    a[2][1] = 2;
    a[2][2] = 4;
    a[2][3] = 11;
    a[3][0] = 6;
    a[3][1] = 10;
    a[3][2] = 15;
    a[3][3] = 14;
    ll x = 0;
    for(int i = 0; i < n; i+=4){
        for(int j = 0; j < n; j+=4){
            loop(i1,i,i+4){
                loop(j1,j,j+4){
                    ans[i1][j1]+=((x<<4)+a[i1%4][j1%4]);
                }
            }
            x++;
        }
    }
    loop(i,0,n){
        loop(j,0,n)cout << ans[i][j] << " ";
        cout << "\n";
    }
   return 0;
}