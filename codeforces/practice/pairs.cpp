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
    int n,m;
    cin >> m >> n;
    V<PII> arr(n);
    loop(i,0,n)cin >> arr[i].F >> arr[i].S;
    V<PII> temp;
    int x = arr[0].F;
    loop(i,0,n){
        if(arr[i].F != x && arr[i].S != x){
            temp.pb(arr[i]);
        }
    }
    bool pos = true;
    loop(i,0,temp.size()){
        if(temp[i].F != temp[0].S && temp[i].S != temp[0].S){
            pos = false;
            break;
        }
    }
    if(pos){
        cout << "YES\n";
        return 0;
    }
    if(!pos){
        pos = true;
        loop(i,0,temp.size()){
            if(temp[i].F != temp[0].F && temp[i].S != temp[0].F){
                pos = false;
                break;
            }
        }
        if(pos){
            cout << "YES\n";
            return 0;
        }
    }

    temp = V<PII>();
    x = arr[0].S;
    loop(i,0,n){
        if(arr[i].F != x && arr[i].S != x){
            temp.pb(arr[i]);
        }
    }
    pos = true;
    loop(i,0,temp.size()){
        if(temp[i].F != temp[0].S && temp[i].S != temp[0].S){
            pos = false;
            break;
        }
    }
    if(pos){
        cout << "YES\n";
        return 0;
    }
    if(!pos){
        pos = true;
        loop(i,0,temp.size()){
            if(temp[i].F != temp[0].F && temp[i].S != temp[0].F){
                pos = false;
                break;
            }
        }
        if(pos){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}