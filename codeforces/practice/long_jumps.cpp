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

int main(){
    int n,l,x,y;
    cin >> n >> l >> y >> x;
    V<int> arr(n);
    unordered_map<int,int> m;
    loop(i,0,n){
        cin >> arr[i];
        m[arr[i]]++;
    }
    loop(i,0,n){
        if(arr[i]+x <=l && m[arr[i]+x])x=0;
        if(arr[i]+y <=l && m[arr[i]+y])y=0;
    }
    if(x+y == 0){
        cout << 0;
        return 0;
    }
    if(x == 0 || y == 0){
        cout << 1 << "\n" << x+y;
        return 0;
    }
    loop(i,0,n){
        // printf("arr[i] = %d, arr[i] + x = %d, m[arr[i]+x] = %d, arr[i]+x-y = %d, m[arr[i]+x-y] = %d\n",arr[i],arr[i]+x,m[arr[i]+x],arr[i]+x-y,m[arr[i]+x-y]);
        if(arr[i]+x <=l && (m[arr[i]+x-y] || m[arr[i]+x+y])){
            cout << 1 << "\n" << arr[i]+x;
            return 0;
        }
        if(arr[i]-x >= 0 && (m[arr[i]-x-y] || m[arr[i]-x+y])){
            cout << 1 << "\n" << arr[i]-x;
            return 0;
        }
    }
    cout << 2 << "\n" << y << " " << x;
   return 0;
}