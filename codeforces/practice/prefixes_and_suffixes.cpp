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

vector<int> z_val(string &a){
    int n = a.size();
    vector<int> z(n,0);
    int L = 0, R = 0;
    for(int i = 0; i < n ; ++i){
        if(i > R){
            L = R = i;
            while(R < n && a[R-L] == a[R])R++;
            z[i] = R-L; R--;
        }else{
            int k = i-L;
            if(z[k] < R-i+1)z[i]=z[k];
            else{
                L=i;
                while(R < n && a[R-L] == a[R])R++;
                z[i] = R-L; R--;
            }
        }
    }
    return z;
}

int main(){
    string a;
    cin >> a;
    auto z = z_val(a);
    vector<int> v(z.begin(),z.end());
    sort(v.begin(),v.end());
    vector<pair<int,int>> ans;
    int cnt = 0;
    int n = a.size();
    for(int i = 1; i < n; ++i){
        cnt = 0;
        if(z[n-i] == i){
            cnt = (v.end() - lower_bound(v.begin(),v.end(),i))+1;
            ans.emplace_back(i,cnt);
        }
    }
    ans.emplace_back(n,1);
    cout << ans.size() << "\n";
    for(auto &i: ans)cout << i.F << " " << i.S << "\n";
   return 0;
}