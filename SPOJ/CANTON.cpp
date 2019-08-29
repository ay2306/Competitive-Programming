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
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin  >> n;
        /*
            N^2 + N - 2n = 0;
            N = { -1 + sqrt(1 + 8n) } / 2
        */
        ll N = (-1 + sqrt(1+8*n))/2;
        // printf("N = %lld  ",N);
        if(n == (N*(N+1))/2){
            // cout << "VERIFIES AS END\n";
            if(N%2 == 1){
                cout << "TERM " << n << " IS 1/" << N << "\n";
            }else{
                cout << "TERM " << n << " IS " << N << "/1\n";
            }
        }else{
            ll term = (N*(N+1))/2 + 1;
            ll num,denom,da,na;
            if(N % 2 == 1){
                num = 1;
                na = 1;
                denom = N+1;
                da = -1;
            }else{
                denom = 1;
                num = N+1;
                na = -1;
                da = 1;
            }
            while(term!=n){
                // printf("term = %lld, %lld/%lld\n",term,num,denom);
                term++;
                denom+=da;
                num+=na;
            }
            cout << "TERM " << n << " IS " << num << "/" << denom << "\n";
        }
    }
   return 0;
}