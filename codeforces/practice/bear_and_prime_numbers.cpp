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
const int N = 1e7+1;
int p[N];
ll s[N];
int main(){
    FAST
    for(int i = 2; i < N; ++i){
        if(p[i] == 0){
            for(int j = i; j < N; j+=i){
                p[j] = i;
            }
        }
    }
    int n,a,k;
    cin >> n;
    loop(i,0,n){
        cin >> a;
        while(a > 1){
            s[p[a]]++;
            k = p[a];
            while(a%k == 0)a/=k;
        }
    }
    loop(i,1,N)s[i]+=s[i-1];
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        if(l >= N){
            cout << 0 << "\n";
            continue;
        }else{
            r = min(r,N-1);
        }
        cout << s[r]-s[l-1] << "\n";
    }
   return 0;
}