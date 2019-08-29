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

void solve(){
    int n,m;
    cin >> n >> m;
    map<PII,int> anteater;
    V<P<char,PII>> ants;
    V<P<char,PII>> temp;
    loop(i,0,n){
        string a;
        cin >> a;
        loop(j,0,m){
            if(a[j] == '#'){
                anteater[mp(i,j)]++;
            }else if(a[j] != '-'){
                ants.pb(mp(a[j],mp(i,j)));
            }
        }
    }
    int ans = 0;
    loop(i,0,max(n,m)+1){
        temp.clear();
        map<PII,int> pos;
        for(auto &j: ants){
            int y = j.S.F;
            int x = j.S.S;
            switch (j.F)
            {
                case 'R': x++; break;
                case 'L': x--; break;
                case 'U': y--; break;
                case 'D': y++; break;
            }
            if(x < 0 || x >= m || y < 0 || y >= n)continue;
            if(anteater.find(mp(y,x)) != anteater.end()){
                continue;
            }
            ans+=pos[mp(y,x)];
            pos[mp(y,x)]++;
            temp.pb(mp(j.F,mp(y,x)));
        }
        ants = temp;
    }
    cout << ans << "\n";
}

int main(){
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}