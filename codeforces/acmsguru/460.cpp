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
    while(n--){
        string a;
        cin >> a;
        int sit = 0;
        switch (a.back())
        {
            case 'h': if(a[a.size()-2] == 'c')sit = 1;break;
            case 'x':
            case 's':
            case 'o': sit = 1; break;
            case 'f': sit = 2; break;
            case 'e': if(a[a.size()-2] == 'f')sit = 3; break;
            case 'y': sit = 4;
        }
        switch (sit)
        {
            case 0: cout << a << "s" << "\n"; break;
            case 1: cout << a << "es" << "\n"; break;
            case 2: loop(i,0,a.size()-1)cout << a[i]; cout << "ves\n"; break;
            case 3: loop(i,0,a.size()-2)cout << a[i]; cout << "ves\n"; break;
            case 4: loop(i,0,a.size()-1)cout << a[i]; cout << "ies\n"; break;
        }
    }
   return 0;
}