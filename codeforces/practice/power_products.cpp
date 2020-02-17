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
const ll N = 1e5+100;
const ll inf = 1e9;
const double pi = acos(-1);
int pr[N];
void pre(){
    loop(i,2,N){
        if(pr[i])continue;
        loops(j,i,N,i)pr[j]=i;
    }

}
int main(){
    pre();
    int n,k;
    cin >> n >> k;
    map<set<PII>,int> avail;
    ll ans = 0;
    ll empty = 0;
    loop(i,0,n){
        int a;
        cin >> a;
        unordered_map<int,int> m;
        while(a > 1){
            m[pr[a]]++;
            a/=pr[a];
        }
        set<PII> req;
        set<PII> this_set;
        for(auto j: m){
            int rem = j.S%k;
            if(rem == 0)continue;
            req.insert(mp(j.F,k-rem));
            this_set.insert(mp(j.F,rem));
        }
        if(req.size() == 0){
            ans+=empty;
            empty++;
        }else{
            ans+=avail[req];
            avail[this_set]++;
        }
    }
    cout << ans << "\n";
   return 0;
}