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
    FAST
    int n,m;
    cin >> n >> m;
    V<P<PII,int>> arr(m);
    loop(i,0,m){
        cin >> arr[i].F.F >> arr[i].F.S;
        arr[i].S = i;
    }
    sort(all(arr),[](P<PII,int>&a, P<PII,int> &b)->bool{
        return (a.F.F < b.F.F || (a.F.F == b.F.F && a.F.S > b.F.S));
    });
    V<int> inc(1,1);
    V<PII> ans(m);
    int mst = 1;
    int i = 3;
    int j = 3;
    for(auto k: arr){
        // printf("w = %d, inc = %d, ind = %d\n",k.F.F,k.F.S,k.S);
        if(k.F.S == 1){
            ans[k.S] = {1,++mst};
        }else{
            if(mst < 3){
                cout << -1;
                return 0;
            }
            i--;
            if(i == 1){
                j++;
                i = j-1;
                if(j > mst){
                    cout << "-1";
                    return 0;
                }
            }
            ans[k.S] = {i,j};
        }
    }
    // cout << "---------\n";
    for(auto k: ans)cout << k.F << " " << k.S << "\n";
   return 0;
}