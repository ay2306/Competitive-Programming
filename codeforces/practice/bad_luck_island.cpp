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
const ll N = 1e2+5;
const ll inf = 1e9;
const double pi = acos(-1);
ld dp[N][N][N];
int main(){
    int n,m,l;
    scanf("%d%d%d",&n,&l,&m);
    dp[n][m][l] = 1;
    for(int sum = n+m+l; sum > 0; sum--){
        for(int r = n; r >= 0; r--){
            for(int p = m; p >= 0; p--){
                int s = sum - p - r;
                if(s > l || s < 0)continue;
                if(p == 0 && r == 0)continue;
                if(s == 0 && r == 0)continue;
                if(p == 0 && s == 0)continue;
                ld cur = dp[r][p][s];
                ld waysR = r*s;
                ld waysS = s*p;
                ld waysP = p*r;
                ld tot = waysR + waysP + waysS;
                if(r > 0)dp[r-1][p][s] += cur*(waysP/tot);
                if(p > 0)dp[r][p-1][s] += cur*(waysS/tot);
                if(s > 0)dp[r][p][s-1] += cur*(waysR/tot);

            }
        }
    }
    ld r = 0,p = 0,s = 0;
    loop(i,1,n+1)r+=dp[i][0][0];
    loop(i,1,m+1)p+=dp[0][i][0];
    loop(i,1,l+1)s+=dp[0][0][i];
    printf("%.10Lf %.10Lf %.10Lf",r,s,p);
   return 0;
}