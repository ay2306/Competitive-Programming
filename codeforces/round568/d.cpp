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
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

int main(){
    int n;
    cin >> n;
    V<PLL> arr(n);
    loop(i,0,n){
        cin >> arr[i].F;
        arr[i].S = i+1;
    }
    sort(all(arr));
    if(n == 2 || n == 3){
        cout << arr.begin()->second ;
        return 0;
    }
    int diff = 0;
    int ind = -1;
    bool check_second = false;
    ll c = arr[1].F-arr[0].F;
    ll k = 1;
    loop(i,1,n){
        if(arr[i].F != k*c + arr[0].F){
            diff++;
            ind = arr[i].S;
        }else{
            k++;
        }
    }
    if(diff == 0){
        cout << arr[0].S;
        return 0;
    }
    if(diff == 1){
        cout << ind ;
        return 0;
    }
    diff = 0;
    c = arr[2].F - arr[0].F;
    k = 1;
    loop(i,2,n){
        if(arr[i].F != k*c + arr[0].F){
            diff++;
            ind = arr[i].S;
        }else{
            k++;
        }
    }
    if(diff == 0){
        cout << arr[1].S;
        return 0;
    }
    diff = 0;
    c = arr[2].F - arr[1].F;
    k = 1;
    loop(i,2,n){
        if(arr[i].F != k*c + arr[1].F){
            diff++;
            ind = arr[i].S;
        }else{
            k++;
        }
    }
    if(diff == 0){
        cout << arr[0].S;
        return 0;
    }
    cout << "-1";
    return 0;
}