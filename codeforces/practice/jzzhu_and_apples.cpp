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
    int n;
    cin >> n;
    if(n < 4){
        cout << 0;
        return 0;
    }
    V<int> p(n+10,0);
    loop(i,2,n+10){
        if(p[i] == 0){
            for(int j = 2; i*j < n+10; ++j)p[i*j]=i;
            i+=(i%2);
        }
    }
    V<int> primes;
    V<PII> ans;
    loops(i,3,n+10,2){
        if(i > n/2)break;
        if(p[i] == 0)primes.pb(i);
    }
    V<bool> mark(n+10,false);
    for(int i = 0; i < primes.size(); ++i){
        list<int> l;
        // printf("prime = %d: ",primes[i]);
        for(int j = 2; primes[i]*j <= n; ++j){
            if(!mark[primes[i]*j]){
                l.pb(primes[i]*j);
                mark[primes[i]*j] = true;
            }
        }
        if(!l.empty() && l.size() % 2 == 0){
            mark[l.front()] = false;
            l.pop_front();
        }
        if(!l.empty()) l.push_front(primes[i]);
        // printf("list = ");
        // for(auto &k: l)cout << k << " ";
        // printf("\n");
        while(!l.empty()){
            int a = l.back();
            l.pop_back();
            int b = l.back();
            l.pop_back();
            ans.pb(mp(a,b));
        }
    }
    list<int> e;
    loops(i,2,n+1,2){
        if(!mark[i])e.pb(i);
        // cout << i << "\n";
    }
    while(e.size() > 1){
        int a = e.back();
        e.pop_back();
        int b = e.back();
        e.pop_back();
        ans.pb(mp(a,b));
    }
    cout << ans.size() << "\n";
    for(auto &i: ans){
        cout << i.F << " " << i.S << "\n";
    }
   return 0;
}