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
map<pair<double,double>,int> m;
map<int, int> x;
map<int, int> y;
int main(){
    int n;
    int ans = 2;
    cin >> n;
    pair<double,double> arr[n];
    loop(i,0,n)cin >> arr[i].F >> arr[i].S;
    loop(i,0,n){
        loop(j,i+1,n){
            double x1 = arr[i].F;
            double x2 = arr[j].F;
            double y1 = arr[i].S;
            double y2 = arr[j].S;
            if(y2 == y1){
                y[y1]++;
                y[y1]++;
                ans = max(y[y1],ans);
            }
            else if(x1 == x2){
                x[x1]++;
                x[x1]++;
                ans = max(x[x1],ans);
            }
            else{
                double slope = y2-y1;
                slope/=(x2-x1);
                double c = -x1*slope + y1;
                // if(m.find(mp(slope,c)) != m.end()){
                //     m[mp(slope,c)]++;
                // }else{
                // }
                m[mp(slope,c)]+=2;
                // printf("%d %d slope = %f c = %f val = %d\n",i,j,slope,c,m[mp(slope,c)]);
                ans = max(m[mp(slope,c)],ans);
            }
        }
    }
    ans = (1 + sqrt(ans+ans+ans+ans+1))/2;
    cout << ans;
   return 0;
}