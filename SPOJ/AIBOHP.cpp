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
string str;
const int N = 6110;
int dp[N][N];
int getMinInsertion(int l = 0, int h = str.size()-1){
    if(dp[l][h] != -1)return dp[l][h];
    if(l > h)return str.size()*10;
    if(h-l <= 1)return (str[l] != str[h]);
    if(str[l] == str[h])dp[l][h] = getMinInsertion(l+1,h-1);
    else dp[l][h] = min(getMinInsertion(l+1,h)+1,getMinInsertion(l,h-1)+1);
    return dp[l][h];
}

int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        cin >> str;
        memset(dp,-1,sizeof(dp));
        cout << getMinInsertion() << "\n";
    }
   return 0;
}