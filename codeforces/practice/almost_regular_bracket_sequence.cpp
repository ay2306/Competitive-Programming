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
    int n;
    cin >> n;
    string a;
    cin >> a;
    V<int> ore(n,0);
    V<int> cre(n,0);
    V<int> cm(n,0);
    V<int> om(n,0);
    int ans = 0;
    loop(i,0,n){
        cm[i] = cm[i-1];
        if(i > 0 && a[i-1] == '('){
            cre[i] = cre[i-1]+1;
        }else if(i > 0){
            if(cre[i-1] == 0){
                cm[i]++;
            }else{
                cre[i] = cre[i-1]-1;
            }
        }
    }
    loopr(i,n-1,0){
        if(a[i+1] == ')' && i < n-1){
            om[i] = om[i+1];
            ore[i] = ore[i+1]+1;
        }else if(i < n-1){
            om[i] = om[i+1];
            if(ore[i+1] == 0){
                om[i]++;
            }else{
                ore[i] = ore[i+1]-1;
            }
        }
    }
    // loop(i,0,n){
    //     printf("%3d ",ore[i]);
    // }
    // printf("\n");
    // loop(i,0,n){
    //     printf("%3d ",om[i]);
    // }
    // printf("\n");
    // loop(i,0,n){
    //     printf("%3d ",cre[i]);
    // }
    // printf("\n");
    // loop(i,0,n){
    //     printf("%3d ",cm[i]);
    // }
    // printf("\n");
    loop(i,0,n){
        int o,c;
        if(om[i] || cm[i]){
            continue;
        }
        if(a[i] == ')'){
            o = ore[i];
            c = cre[i]+1;
        }else{
            o = ore[i]+1;
            c = cre[i];
        }
        if(o == c && o >= 0 && c >= 0){
            ans++;
        }
        // printf("o = %3d, c = %3d  i = %d\n",o,c,i);
    }
    cout << ans;
   return 0;
}