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
const int N = 30;
int arr[N][N];
int n,m;
string ans = "";
int x[] = { 2 , 2 , -2 , -2 , 1 , -1 ,  1 , -1 };
int y[] = { -1, 1 , -1 ,  1 , 2 ,  2 , -2 , -2 };
bool fill(int i, int j, int done){
    string current = "";
    int op = j+1;
    while(op){
        current+=char(op%10 + '0');
        op/=10;
    }
    current+=char('A'+i);
    if(done == m*n){
        ans+=current;
        return true;
    }
    bool pos = false;
    set<PII> s;
    arr[i][j] = 1;
    loop(k,0,8){
        PII a = mp(i+x[k],j+y[k]);
        if(a.first >= 0 && a.first < n && a.second >= 0 && a.second < m){
            if(arr[a.F][a.S] == 0)s.insert(a);
        }
    }
    // printf("\nFrom (%d, %d) => ",i,j);
    for(auto o: s){
        // printf("(%d, %d) => ", o.F,o.S);
        if(fill(o.F,o.S,done+1)){
            ans+=current;
            return true;
        }
    }
    // printf(" BACK <== (done = %d) ", done);
    arr[i][j] = 0;
    return false;
}

void solve(){
    cin >> m >> n;
    loop(i,0,n){
        loop(j,0,m){
            arr[i][j] = 0;
        }
    }
    ans = "";
    if(fill(0,0,1)){
        reverse(all(ans));
        cout << ans << "\n";
    }else{
        cout << "-1\n";
    }
}

int main(){
    // FILE_READ_OUT
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}