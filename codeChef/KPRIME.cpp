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
const ll maxn = 1e5+10;
const ll inf = 1e9;
const double pi = acos(-1);

int main(){
    int kp[maxn] = {0};
    for(int i = 2; i < maxn; ++i){
        if(kp[i] == 0){
            for(int j = 1; i*j < maxn; ++j)kp[i*j] = i;
        }
    }
    V<V<int>> arr(maxn,V<int>(5,0));
    for(int i = 2; i < maxn; ++i){
        unordered_map<int,int> m;
        int val = i;
        while(val > 1){
            m[kp[val]]++;
            val/=kp[val];
        }
        if(m.size() > 5)continue;
        arr[i][m.size()-1]++;
    }
    for(int i = 1; i < maxn; ++i){
        for(int j = 0; j < 5; ++j){
            arr[i][j]+=arr[i-1][j];
        }
    }
    int t;
    cin >> t;
    while(t--){
        int a,b,k;
        cin >> a >> b >> k;
        cout << arr[b][k-1] - arr[a-1][k-1] << "\n";
    }
   return 0;
}