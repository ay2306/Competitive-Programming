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
    int t;
    cin >> t;
    while(t--){
        ll arr[3];
        loop(i,0,3)cin >> arr[i];
        sort(arr,arr+3);
        ll all_pos,n1,n2,n3;
        ll ans;
        n1 = arr[0]%MOD;
        n2 = arr[1]%MOD;
        n3 = arr[2]%MOD;
        all_pos = (n1*n2)%MOD;
        all_pos = (all_pos*n3)%MOD;
        all_pos = (all_pos - n1 + MOD)%MOD;//For cases where all three can be same
        all_pos = (all_pos - (n1*((n3-1+MOD)%MOD))%MOD + MOD)%MOD;//For cases where number from n1 and n2 will be same but not from n3
        all_pos = (all_pos - (n1*((n2-1+MOD)%MOD))%MOD + MOD)%MOD;//For cases where number from n1 and n3 will be same but not from n2
        all_pos = (all_pos - ((((n1-1+MOD)%MOD)*n1)%MOD + MOD))%MOD;//For cases where number from n2 and n3 will be same but not from n1 but n2,n3 lies in n1 range
        all_pos = (all_pos - (n1*((n2-n1+MOD)%MOD))%MOD + MOD)%MOD;//For cases where number from n2 and n3 will be same but not from n1 but n2,n3 do not lies in n1 range
        ans = all_pos;
        if(ans < 0)ans+=MOD;
        cout << ans << "\n";
    }
    return 0;
}